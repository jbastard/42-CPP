/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumephilippe <guillaumephilippe@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:45:32 by guillaumeph       #+#    #+#             */
/*   Updated: 2025/07/21 19:45:11 by guillaumeph      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <limits>

class PMergeMe {
	private:
		PMergeMe(const PMergeMe& copy);
		PMergeMe& operator=(const PMergeMe& other);
		// vectors part
		std::vector<int> _inputVector;
		std::vector<int> _smallerPairsVec;
		std::vector<int> _largerPairsVec;
		bool _hasLeftOverVec;
		int _leftOverVec;
		// deque part
		std::deque<int> _inputDeque;
		std::deque<int> _smallerPairsDeq;
		std::deque<int> _largerPairsDeq;
		bool _hasLeftOverDeq;
		int _leftOverDeq;
		
	public:
		PMergeMe();
		~PMergeMe(); 
		// exec
		void run(int argc, char **argv); 
		//poarser
		void parseInput(int argc, char **argv);
		void checkDuplicates(const std::vector<int>& data) const;
		void checkDuplicates(const std::deque<int>& data) const;
		//sort logic
		void mergeSort(std::vector<int>& vec, int left, int right);
		void mergeSort(std::deque<int>& deq, int left, int right);
		void fordJohnsonSortVec(std::vector<int>& data);
		void fordJohnsonSortDeq(std::deque<int>& data);
		//pair logic
		void createPairVec(std::vector<int>& data);
		void createPairDeq(std::deque<int>& data);
		//utils
		void printContainerVec(const std::string& name, const std::vector<int>& vec);
		void printContainerDeq(const std::string& name, const std::deque<int>& deq);
};