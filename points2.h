/*
Author: Marco Valero
File Title: points2.h

Description: This class implements a "sequence" of coordinates (x, y) using C++11 semantics and the "big 5". (Copy Constructor, Copy Assignment Operator, Move Constructor, Move Assignment Operator and Destructor)

Object member ReadPoints2() is implemented so that the user can input its own "sequence". The user must first enter the size of the "sequence", followed by the coordinates (x, y).
Example: 3 7 4 3 2 1 10
3 specifies number of points. Points are the pairs:
(7, 4) (3, 2) and (1, 10).

Date of creation: February 2nd, 2019
Date of completition: February 8th, 2019
Date of modifications: February 12th, 2019.

Purpose: To get comfortable with C++11 semantics and the implementations of the "Big 5"

To run:
make clean
make all
./test_points2

*/

#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
#include <string>

template<typename Object>
class Points2 {
public:
  /*
  Zero-parameter constructor.
  */
  Points2() : sequence_(nullptr), size_(0) { }

  // One parameter constructor.
  explicit Points2(const std::array<Object, 2>& item) {
    size_ = item.size()/2;
    sequence_ = new std::array<Object, 2>{item};
  }

  size_t size() const {
    return size_;
  }

  /*
  Copy-constructor.
  Pre-condition: rhs must be a lvalue
  Post-condition: A new object is created such that it is the same as rhs. rhs remains the same.
  (BIG FIVE)
  */
  Points2(const Points2 &rhs) {
    // if rhs is empty (no sequence)
    if (rhs.size() == 0) {
      size_ = 0;
      sequence_ = nullptr;
    } else { // if rhs has a sequence
        size_ = rhs.size();
        //alllocate memory dynamically to be able to copy
        sequence_ = new std::array<Object, 2>[size_];
        std::copy(rhs.sequence_, rhs.sequence_+rhs.size_, sequence_);
    }
  }

  /*
  Move-constructor.
  For statement such as ClassName ObjectName = std::move(ConstructedObjectName)
  Pre-condition: rhs must be a rvalue
  Post-condition: A new object is created such that it is the same as rhs. rhs is now set to nullptr
  (BIG FIVE)
  */
  Points2(Points2 &&rhs) : sequence_(rhs.sequence_), size_(rhs.size_) {
    rhs.sequence_ = nullptr;
    rhs.size_ = 0;
  }

  /*
  Copy-assignment.
  For statements such as lhs = rhs where lhs and rhs are already constructed.
  Pre-condition: rhs must be a lvalue
  Post-condition: lhs is created such that it is the same as rhs. rhs remains the same
  (BIG FIVE)
  */
  Points2& operator=(const Points2 &rhs) {
    Points2 copy = rhs; //
    std::swap(*this, copy);
    return *this;
  }

  /*
  Move-assignment.
  For statements such as ConstructedObjectName = std::move(ConstructedObjectName)
  Pre-condition: rhs must be a rvalue
  Post-condition: lhs is created such that it is the same as rhs.
  (BIG FIVE)
  */
  Points2& operator=(Points2 &&rhs) {
    if (this != &rhs) {
      std::swap(size_, rhs.size_);
      std::swap(sequence_, rhs.sequence_);
    }
    return *this;
  }

  /*
  Destructor
 (BIG FIVE)
  */
  ~Points2() {
    delete [] sequence_;
    sequence_ = nullptr;
  }

  // Read a chain from standard input.
  void ReadPoints2() {
    std::string input_line;
    std::getline(std::cin, input_line);
    std::stringstream input_stream(input_line);
    if (input_line.empty())
      return;
    // Read size of sequence (an integer).
    int size_of_sequence;
    input_stream >> size_of_sequence;
    // Allocate space for "sequence" & sequence_ ptr points to dynamic array of type std::array<Object, 2>
    size_ = size_of_sequence;
    sequence_ = new std::array<Object, 2>[size_of_sequence];
    // reads the rest of the input line the user entered
    Object token;
    for (int i = 0 ; input_stream >> token; ++i) {
      sequence_[i][0] = token;
      input_stream >> token;
      sequence_[i][1] = token;
    }
  }

  /*
  Overloading the << operator.
  Post-condition: Prints out the "sequence" in form: (x, y) (x, y) ...
  */
  friend std::ostream& operator<<(std::ostream &out, const Points2 &some_points2) {
    // size 1 sequence is only a std::array<Object, 2>
    if (some_points2.sequence_ != nullptr && some_points2.size_ == 1) {
      out << "(" << some_points2.sequence_->at(0) << ", " << some_points2.sequence_->at(1) << ")";
    }
    // for sequences with size > 1, I used a dynamic array of type std::array<Object, 2>
    if (some_points2.sequence_ != nullptr && some_points2.size_ > 1) {
      for (size_t i = 0; i < some_points2.size_; i++) {
        out << "(" << some_points2.sequence_[i][0] << ", " << some_points2.sequence_[i][1] << ")" << " ";
      }
    }
    if (some_points2.sequence_ == nullptr) {
      out << "()";
    }
    out << std::endl;
    return out;
  }

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const {
    if (location < 0 || location >= size_) {
      std::cout << "Location out-of-range\n";
      abort();
    } else
        return sequence_[location];
  }

  //  @c1: A sequence.
  //  @c2: A second sequence.
  //  @return their sum. If the sequences are not of the same size, append the result with the remaining part of the larger sequence.
   friend Points2 operator+(const Points2 &c1, const Points2 &c2) {
   Points2<Object> result_seq;
   // if c1 is the greater one
   if (c1.size_ > c2.size_) {
      result_seq.size_ = c1.size_;
      result_seq.sequence_ = new std::array<Object, 2> [result_seq.size_];
    } else {
        result_seq.size_ = c2.size_;   // c2 is greater or equal
        result_seq.sequence_ = new std::array<Object, 2> [result_seq.size_];
      }
    for (size_t i = 0; i < result_seq.size_; i++) {
      result_seq.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
      result_seq.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
    }
    return result_seq;
  }

private:
  // Sequence of points.
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

};

#endif // CSCI_335_HOMEWORK1_POINTS2_H_
