/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:08:35 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/12 16:36:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# include "vector.hpp"
// # include "map.hpp"
# include "stack.hpp"
// # include "iterator_traits.hpp"
// # include "reverse_iterator.hpp"
// # include "enable_if.hpp"
// # include "is_integral.hpp"
// # include "equal.hpp"
# include "lexicographical_compare.hpp"
// # include "pair.hpp"
// # include "make_pair.hpp"

#include <vector>
#include <string>
#include <stack>

#define FT

int main() {
	#ifdef FT
		std::cout << "=== FT DEFINED ===\n";
		ft::stack<int> alice;
		ft::stack<int> bob;
		ft::vector<int> stone;
		ft::vector<int> cha;
		// ft::stack<int>::iterator it;
	#endif
	#ifdef STL
		std::cout << "=== STL DEFINED ===\n";
		std::stack<int> alice;
		std::stack<int> bob;
		std::vector<int> stone;
		std::vector<int> cha;
		// std::stack<int>::iterator it;
	#endif

	alice.top();
	for (int i = 0; i < 10; i++) {
		alice.push((i + 1) * 10);
	}
	if (alice.empty())
		std::cout << "alice is empty\n";


	if (alice.empty())
		std::cout << "alice is empty\n";

	for (int i = 0; i < static_cast<int>(bob.size()); i++) {
		std::cout << "bob  :" << bob.top() << "\n";
		// bob.pop();
	}

	bob = alice;


	if (bob == alice)
		std::cout << "bob is equal to alice\n";
	if (bob != alice)
		std::cout << "bob != alice\n";
	if (bob < alice)
		std::cout << "bob < alice\n";
	if (bob > alice)
		std::cout << "bob > alice\n";
	if (bob <= alice)
		std::cout << "bob <= alice\n";
	if (bob >= alice)
		std::cout << "bob >= alice\n";
	
	for (int i = 0; i < 10; i++) {
		stone.push_back((i + 1) * 10 );
	}
	cha = stone;
		if (cha == stone)
		std::cout << "cha is equal to stone\n";
	if (cha != stone)
		std::cout << "cha != stone\n";
	if (cha < stone)
		std::cout << "cha < stone\n";
	if (cha > stone)
		std::cout << "cha > stone\n";
	if (cha <= stone)
		std::cout << "cha <= stone\n";
	if (cha >= stone)
		std::cout << "cha >= stone\n";
	// ------------------------------------------- //

	// for (int i = 0; i < 127; i++) {
	// 	alice.push_back(i);
	// }
	// std::cout << "alice size           : " << alice.size() << "\n";
	// std::cout << "1 - alice.capacity() : " << alice.capacity() << "\n";
	// // std::cout << "1 - bob.capacity()   : " << bob.capacity() << "\n";
	// alice.reserve(alice.max_size() + 1);
	// std::cout << "2 - alice.capacity() : " << alice.capacity() << "\n";

	// std::cout << "\n";
	// alice = bob;
	// std::cout << "--- alice = bob ---\n";
	// std::cout << "2 - alice.capacity() : " << alice.capacity() << "\n";
	// std::cout << "3 - bob.capacity()   : " << bob.capacity() << "\n";

	// --------------------------------------- //
	// alice.push_back(1);
	// alice.push_back(2);
	// alice.push_back(3);
	// bob.push_back(7);
	// bob.push_back(8);
	// bob.push_back(9);
	// bob.push_back(10);
 
    // // Print state before swap
    // std::cout << "alice:";
    // for (it = alice.begin(); it != alice.end(); it++)
	// 	std::cout << *it << " ";
    // std::cout << "\n" "bob  :";
    // for (it = bob.begin(); it != bob.end(); it++)
	// 	std::cout << *it << " ";
    // std::cout << '\n';
 
    // std::cout << "-- SWAP\n";
	// #ifdef FT
    // 	ft::swap(alice, bob);
	// #endif
	// #ifdef STL
    // 	std::swap(alice, bob);
	// #endif
    // // Print state after swap
    // std::cout << "alice:";
    // for (it = alice.begin(); it != alice.end(); it++)
	// 	std::cout << *it << " ";
    // std::cout << "\n" "bob  :";
    // for (it = bob.begin(); it != bob.end(); it++)
	// 	std::cout << *it << " ";
    // std::cout << '\n';


	// -------------------------------------- //
	// ----> NON MEMBER FUNCTIONS TESTS <---- //

	// #ifdef FT
	// ft::vector<int> alice;
	// ft::vector<int> bob;
	// ft::vector<int> eve;
	// #endif
	// #ifdef STL
	// 	std::vector<int> alice;
	// 	std::vector<int> bob;
	// 	std::vector<int> eve;
	// #endif

	// alice.push_back(2);
	// alice.push_back(3);
	// bob.push_back(7);
	// bob.push_back(8);
	// bob.push_back(9);
	// bob.push_back(10);
	// eve.push_back(1);
	// eve.push_back(2);
	// eve.push_back(3);
	

    // std::cout << std::boolalpha << "\n";
 
    // // Compare non equal containers
    // std::cout << "alice == bob returns " << (alice == bob) << '\n';
    // std::cout << "alice != bob returns " << (alice != bob) << '\n';
    // std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    // std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    // std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    // std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    // std::cout << '\n';
 
    // // Compare equal containers
    // std::cout << "alice == eve returns " << (alice == eve) << '\n';
    // std::cout << "alice != eve returns " << (alice != eve) << '\n';
    // std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    // std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    // std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    // std::cout << "alice >= eve returns " << (alice >= eve) << '\n';

	// -------------------------------------------------- //
	// #ifdef FT
	// 	std::cout << "------ FT DEFINED ------\n";
	// 	ft::vector<int> ftvec;
	// 	ft::define
	// for (int i = 0; i < 20; i++) {
	// 	ftvec.push_back((i + 1) * 10);
	// }
	// for (int i = 0; i < 20; i++) {
	// 	std::cout << "vec init : " << ftvec[i] << "\n";
	// }

	// #ifdef FT
	// 	ft::vector<int> ftvec2;
	// #endif
	// #ifdef STL
	// 	std::vector<int> ftvec2;
	// #endif

	// for (int i = 0; i < 5; i++) {
	// 	ftvec2.push_back((i + 1) * 500);
	// }
	// std::cout << "\n";
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << "vec2 init : " << ftvec2[i] << "\n";
	// }

	// ftvec.swap(ftvec2);
	// std::cout << "After swap.\n";
	// for (itbegin = ftvec.begin(); itbegin != ftvec.end(); itbegin++) {
	// 	std::cout << " - vec : " << *itbegin << "\n";
	// }
	// std::cout << "\n";
	// for (itbegin = ftvec2.begin(); itbegin != ftvec2.end(); itbegin++) {
	// 	std::cout << " - vec2 : " << *itbegin << "\n";
	// }

	// -------------------------------------------------- //
	// -------------------------------------------------- //
	// initializing char arrays
    // char one[] = "geeksforgeek";
    // char two[] = "geeksforgeeks";
      
    // // using lexicographical_compare for checking 
    // // is "one" is less than "two"
    // if( ft::lexicographical_compare(one, one+13, two, two+13))
    // {
    //     std::cout << "geeksforgeeks is lexicographically less than gfg";
          
    // }
    // else
    // {
    //     std::cout << "geeksforgeeks is not lexicographically less than gfg";
          
    // }
	
	// -------------------------------------  //
	// -------------------------------------- //
	// ftvec.insert(ftvec.begin() + 2, ftvec2.begin(), ftvec2.end());
	// std::cout << "After insert.\n";
	
	// for (itbegin = ftvec.begin(); itbegin != ftvec.end(); itbegin++) {
	// 	std::cout << "- vec : " << *itbegin << "\n";
	// }
	// ------------------------------------- //

	// for (int i = 0; i < 20; i++) {
	// 	ftvec.push_back((i + 1) * 10);
	// }

	// itbegin = ftvec.begin();
	// itend = ftvec.end();
	// int *p = ftvec.data();

	// for (size_t i = 0; i < ftvec.size(); i++) {
	// 	std::cout << "p : " << *(p + i) << "\n";
	// }

	// #ifdef FT
	// 	ft::vector<int> ftvec2(itbegin, itbegin + 1);
	// #endif
	// #ifdef STL
	// 	std::vector<int> ftvec2(itbegin, itbegin + 1);
	// #endif

	// std::cout << "After calling templated constructor\n";
	// p = ftvec2.data();
	// for (size_t i = 0; i < ftvec2.size(); i++) {
	// 	std::cout << "p vec2 : " << *(p + i) << "\n";
	// }
	// std::cout << "size : " << ftvec2.size() << " | capacity : " << ftvec2.capacity() << "\n";

	// ftvec.clear();
	// for (int i = 0; i < 5; i++) {
	// 	ftvec.push_back(i * 20);
	// }
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << "vec : " << ftvec[i] << "\n";
	// }

	// ftvec2.assign(ftvec.begin(), ftvec.end());
	// std::cout << "after iterator assign\n";

	// for (itbegin = ftvec2.begin(); itbegin < ftvec2.end(); itbegin++) {
	// 	std::cout << "- vec 2 : " << *itbegin << "\n";
	// }
	 

	// ------------------------------------------ //

	// for (int i = 0; i < 20; i++) {
	// 	ftvec.push_back((i + 1) * 10);
	// }
	// int *p = ftvec.data();

	// for (size_t i = 0; i < ftvec.size(); i++) {
	// 	std::cout << "p : " << *(p + i) << "\n";
	// }
	// itbegin = ftvec.end();
	// itend = ftvec.insert(itbegin, 1337);
	// std::cout << "itend : " << *itend << "\n";
	// p = ftvec.data();
	// std::cout << "After insert.\n";
	// for (size_t i = 0; i < ftvec.size(); i++) {
	// 	std::cout << "p : " << *(p + i) << "\n";
	// }

	// ---------------------------------------- //

	// ftvec.assign(10, 1337);
	// std::cout << "assign done.\n";
	// p = ftvec.data();
	// for (size_t i = 0; i < ftvec.size(); i++) {
	// 	std::cout << "p : " << *(p + i) << "\n";
	// }

	// --------------------------------------------------------- //
	// itbegin = ftvec.rbegin();
	// itend = ftvec.rend();
	// // Be careful reading itend will cause invalid read
	// std::cout << "itbegin     : " << *itbegin << "\n";// " | itend : " << *itend << "\n" ; 

	// std::cout << "itbegin + 1 : " << *(itbegin + 1) << "\n";
	// std::cout << "itend   - 2 : " << *(itend - 2) << "\n";
	// std::cout << "++itbegin   : " << *(++itbegin) << "\n";
	// std::cout << "--itbegin   : " << *(--itbegin) << "\n";
	// std::cout << "itbegin++   : " << *(itbegin++) << "\n";
	// std::cout << "itbegin aft : " << *itbegin << "\n";
	// std::cout << "itbegin--   : " << *(itbegin--) << "\n";
	// std::cout << "itbegin aft : " << *itbegin << "\n";
	// itbegin += 3;
	// std::cout << "itbegin += 3: " << *itbegin << "\n";
	// itbegin -= 1;
	// std::cout << "itbegin -= 1: " << *itbegin << "\n";
	// std::cout << "itbegin[0]  : " << itbegin[0] << "\n";
	// std::cout << "itbegin[1]  : " << itbegin[1] << "\n";
	// std::cout << "itbegin[2]  : " << itbegin[2] << "\n";
	// int *p = ftvec.data();

	// for (size_t i = 0; i < ftvec.size(); i++) {
	// 	std::cout << "p : " << *(p + i) << "\n";
	// }

	// ft::vector<int>::iterator it = itbegin.base();
	// std::cout << "base it dereferenced : " << *it << "\n";
	// -------------------------------------------------- //
	// ------------------------------- //
	// ftvec.pop_back();
	// ftvec.pop_back();
	// int first = 4;
	// int last = 5;

	// it = ftvec.begin();
	// std::cout << "to erase : " << *(it + first) << " -- " << *(it + last) << "\n";
	// it = ftvec.erase(it + first, it + last);
	//  std::cout << "it returned by erase : " << *it << "\n";
	// if (it == ftvec.end())
	// 	std::cout << "it == ftvec.end()\n";

	// int i = 0;
	// for (it = ftvec.begin(); it != ftvec.end(); it++ ){
	// 	std::cout << ftvec.at(i) << "\n";
	// 	++i;
	// }

	// --------------------------------------------------- //
	// for (it = ftvec.begin(); it != ftvec.end(); it++ ) {
	// 	std::cout << *it << "\n";
	// }


	// std::vector<int> ftvec(2, 42);
	// std::vector<int>::iterator it    = ftvec.begin();
	// std::vector<int>::iterator itend = ftvec.end();



	// if (it ==itend )
	// 	std::cout << "it == itend\n";
	// else
	// 	std::cout << "it != itend\n";


	// std::cout << it[0] << " " << it[1] << " " << it[2] << "\n";

	// it += 1;
	// std::cout << *it << "\n";


	// it = it + 1;
	// if (it < itend)
	// 	std::cout << "it < itend\n";
	// else
	// 	std::cout << "!(it < itend)\n";

	// if (it == itend)
	// 	std::cout << "it == itend\n";
	// else
	// 	std::cout << "!(it == itend)\n";





// --------------------------------------------- //



	// std::cout << *it << "\n";
	// it++;
	// std::cout << *it << "\n";
	// it++;
	// std::cout << *it << "\n";
	// it--;
	// std::cout << *it << "\n";
	// --it;
	// std::cout << *it << "\n";
	// --it;
	// std::cout << *it << "\n";
	// ++it;
	// std::cout << *it++ << "\n";
	// std::cout << *it << "\n";

	return 0;
}