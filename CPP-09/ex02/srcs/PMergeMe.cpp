/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumephilippe <guillaumephilippe@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:45:29 by guillaumeph       #+#    #+#             */
/*   Updated: 2025/07/21 19:55:54 by guillaumeph      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::~PMergeMe() {}

/* ************************************************************************** */
/*  STATIC DECLARATIONS                                                       */
/* ************************************************************************** */

static void merge(std::vector<int>& vec, int left, int mid, int right);
static void merge(std::deque<int>& vec, int left, int mid, int right);
static std::vector<size_t> generateJacobsthalSequenceVec(size_t n);
static std::deque<size_t> generateJacobsthalSequenceDeq(size_t n);

/* ************************************************************************** */
/*  GENERIC UTILS FUNCTIONS                                                   */
/* ************************************************************************** */

void PMergeMe::parseInput(int argc, char **argv)
{
    _inputVector.clear();
    _inputDeque.clear();

    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);

        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!std::isdigit(arg[j]))
                throw std::invalid_argument("Error: invalid input (non digit char).");
        }
        long val = std::strtol(arg.c_str(), NULL, 10);
        if (val < 0 || val > INT_MAX)
            throw std::out_of_range("Error: A value is out of int range.");
        
        _inputVector.push_back(static_cast<int>(val));
        _inputDeque.push_back(static_cast<int>(val));
    }
}

void PMergeMe::checkDuplicates(const std::vector<int>& data) const
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        for (size_t j = i + 1; j < data.size(); ++j)
        {
            if (data[i] == data[j])
            {
                std::ostringstream oss;
                oss << "Error: duplicate value found: " << data[i];
                throw std::runtime_error(oss.str());
            }
        }
    }
}

void PMergeMe::checkDuplicates(const std::deque<int>& data) const
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        for (size_t j = i + 1; j < data.size(); ++j)
        {
            if (data[i] == data[j])
            {
                std::ostringstream oss;
                oss << "Error: dulicate value found: " << data[i];
                throw std::runtime_error(oss.str());
            }
        }
    }
}

void PMergeMe::printContainerVec(const std::string& name, const std::vector<int>& vec)
{
    if (!name.empty())
        std::cout << name << ": ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void PMergeMe::printContainerDeq(const std::string& name, const std::deque<int>& deq)
{
    if (!name.empty())
        std::cout << name << ": ";
    for (size_t i = 0; i < deq.size(); ++i)
        std::cout << deq[i] << " ";
    std::cout << std::endl;
}
/* ************************************************************************** */
/*  VECTORS FORD JOHNSON                                                      */
/* ************************************************************************** */

void PMergeMe::createPairVec(std::vector<int>& data)
{
    _smallerPairsVec.clear();
    _largerPairsVec.clear();
    _hasLeftOverVec = false;
    _leftOverVec = 0;

    size_t i = 0;
    while (i + 1 < data.size())
    {
        int a = data[i];
        int b = data[i + 1];

        if (a < b)
        {
            _smallerPairsVec.push_back(a);
            _largerPairsVec.push_back(b);
        }
        else
        {
            _smallerPairsVec.push_back(b);
            _largerPairsVec.push_back(a);
        }
        i += 2;
    }
    if (i < data.size())
    {
        _hasLeftOverVec = true;
        _leftOverVec = data[i];
    }
}

static void merge(std::vector<int>& vec, int left, int mid, int right)
{
    std::vector<int> leftPart;
    std::vector<int> rightPart;
    
    for (int i = left; i <= mid; ++i)
        leftPart.push_back(vec[i]);
    for (int i = mid + 1; i <= right; ++i)
        rightPart.push_back(vec[i]);

    size_t i = 0, j = 0;
    int k = left;

    while (i < leftPart.size() && j < rightPart.size())
    {
        if (leftPart[i] <= rightPart[j])
            vec[k++] = leftPart[i++];
        else
            vec[k++] = rightPart[j++];
    }
    while (i < leftPart.size())
        vec[k++] = leftPart[i++];
    while (j < rightPart.size())
        vec[k++] = rightPart[j++];
}

void PMergeMe::mergeSort(std::vector<int>& vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

std::vector<size_t> generateJacobsthalSequenceVec(size_t n)
{
    std::vector<size_t> sequence;
    size_t j1 = 1, j2 = 0;
    sequence.push_back(0);

    while (true)
    {
        size_t next = j1 + 2 * j2;
        if (next > n)
            break;
        sequence.push_back(next);
        j2 = j1;
        j1 = next;
    }
    for (size_t i = 1; i < n; ++i)
    {
        if (std::find(sequence.begin(), sequence.end(), i) == sequence.end())
            sequence.push_back(i);
    }
    return sequence;
}

void PMergeMe::fordJohnsonSortVec(std::vector<int>& data)
{
    createPairVec(data);
    mergeSort(_largerPairsVec, 0, _largerPairsVec.size() - 1);
    
    std::vector<int> result = _largerPairsVec;
    
    std::vector<size_t> insertionOrder = generateJacobsthalSequenceVec(_smallerPairsVec.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        size_t index = insertionOrder[i];
        if (index < _smallerPairsVec.size())
        {
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), _smallerPairsVec[index]);
            result.insert(pos, _smallerPairsVec[index]);
        }
    }

    if (_hasLeftOverVec)
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), _leftOverVec);
        result.insert(pos, _leftOverVec);
    }

    _inputVector = result;
}

/* ************************************************************************** */
/*  DEQUE FORD JOHNSON                                                        */
/* ************************************************************************** */

void PMergeMe::createPairDeq(std::deque<int>& data)
{
    _smallerPairsDeq.clear();
    _largerPairsDeq.clear();
    _hasLeftOverDeq = false;
    _leftOverDeq = 0;

    size_t i = 0;
    while (i + 1 < data.size())
    {
        int a = data[i];
        int b = data[i + 1];

        if (a < b)
        {
            _smallerPairsDeq.push_back(a);   
            _largerPairsDeq.push_back(b);
        }
        else
        {
            _smallerPairsDeq.push_back(b);
            _largerPairsDeq.push_back(a);   
        }
        i += 2;
    }
    if (i < data.size())
    {
        _hasLeftOverDeq = true;
        _leftOverDeq = data[i];
    }
}

static void merge(std::deque<int>& deq, int left, int mid, int right)
{
    std::deque<int> leftPart, rightPart;

    for (int i = left; i <=mid; ++i)
        leftPart.push_back(deq[i]);
    for (int i = mid + 1; i <= right; ++i)
        rightPart.push_back(deq[i]);

    size_t i = 0, j = 0;
    int k = left;

    while (i < leftPart.size() && j < rightPart.size())
    {
        if (leftPart[i] <= rightPart[j])
            deq[k++] = leftPart[i++];
        else
            deq[k++] = rightPart[j++];
    }
    while (i < leftPart.size())
        deq[k++] = leftPart[i++];
    while (j < rightPart.size())
        deq[k++] = rightPart[j++];   
}

void PMergeMe::mergeSort(std::deque<int>& deq, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(deq, left, mid);
        mergeSort(deq, mid + 1, right);
        merge(deq, left, mid, right);
    }
}

std::deque<size_t> generateJacobsthalSequenceDeq(size_t n)
{
    std::deque <size_t> sequence;
    size_t j1 = 1, j2 = 0;
    sequence.push_back(0);

    while (true)
    {
        size_t next = j1 + 2 * j2;
        if (next > n)
            break;
        sequence.push_back(next);
        j2 = j1;
        j1 = next;
    }
    for (size_t i = 1; i < n; ++i)
    {
        if (std::find(sequence.begin(), sequence.end(), i) == sequence.end())
            sequence.push_back(i);
    }
    return sequence;
}

void PMergeMe::fordJohnsonSortDeq(std::deque<int>& data)
{
    createPairDeq(data);
    mergeSort(_largerPairsDeq, 0, _largerPairsDeq.size() - 1);

    std::deque<int> result = _largerPairsDeq;
    
    std::deque<size_t> insertionOrder = generateJacobsthalSequenceDeq(_smallerPairsDeq.size());
    
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        size_t index = insertionOrder[i];
        if (index < _smallerPairsDeq.size())
        {
            std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), _smallerPairsDeq[index]);
            result.insert(pos, _smallerPairsDeq[index]);
        }
    }

    if (_hasLeftOverDeq)
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), _leftOverDeq);
        result.insert(pos, _leftOverDeq);
    }

    _inputDeque = result;
}

/* ************************************************************************** */
/*  RUN AND CLOCK                                                             */
/* ************************************************************************** */

void PMergeMe::run(int argc, char **argv)
{
    try
    {
        parseInput(argc, argv);
        checkDuplicates(_inputVector);
        checkDuplicates(_inputDeque);

        std::cout << "Before: ";
        printContainerVec("", _inputVector);

        //timer
        std::vector<int> vecCopy = _inputVector;
        std::deque<int> deqCopy = _inputDeque;

        //vector timer
        clock_t startVec = clock();
        fordJohnsonSortVec(_inputVector);
        clock_t endVec = clock();
        double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

        //deque timer
        clock_t startDeq = clock();
        fordJohnsonSortDeq(_inputDeque);
        clock_t endDeq = clock();
        double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

        std::cout << "After: ";
        printContainerVec("", _inputVector);

        std::cout << "Time to process a range of " << vecCopy.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
        std::cout << "Time to process a range of " << deqCopy.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}