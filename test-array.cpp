#include <gtest/gtest.h>

#include "object.h"  
#include "string.h"  
#include "array.h"    

#define CS4500_ASSERT_TRUE(a)  \
  ASSERT_EQ((a),true);
#define CS4500_ASSERT_FALSE(a) \
  ASSERT_EQ((a),false);
#define CS4500_ASSERT_EXIT_ZERO(a)  \
  ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");
#define CS4500_ASSERT_EXIT_ONE(a)  \
  ASSERT_EXIT(a(), ::testing::ExitedWithCode(1), ".*");
 
// Tests getting, size, and push
void set_get_size_push_test() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * x = new String("HelloWorld");
  Array * a = new Array(3);
  a->push(s);
  a->push(t);
  a->push(x);
  CS4500_ASSERT_TRUE(a->get(2)->equals(x));
  CS4500_ASSERT_TRUE(a->get(1)->equals(t));
  CS4500_ASSERT_TRUE(a->size() == 3);
  a->set(1, s);
  CS4500_ASSERT_TRUE(a->get(1)->equals(s));
  delete s;
  delete t;
  delete x;
  delete a;
  exit(0);
}

TEST(W1, set_get_size_push_test) {
  CS4500_ASSERT_EXIT_ZERO(set_get_size_push_test)
}
 
// Tests indexOf and clear
void indexof_clear_test() {
  String * s = new String("Hello");
  String * t = new String("World");
  Object * u = new Object();
  Array * a = new Array(3);
  a->push(s);
  a->push(t);
  a->push(u);
  CS4500_ASSERT_TRUE(a->indexOf(t) == 1);
  CS4500_ASSERT_TRUE(a->indexOf(s) == 0);
  CS4500_ASSERT_TRUE(a->indexOf(s, 1) == -1);
  a->set(2, s);
  CS4500_ASSERT_TRUE(a->indexOf(s, 1) == 2);
  a->clear();
  CS4500_ASSERT_TRUE(a->indexOf(t) == -1);
  delete s;
  delete t;
  delete u;
  delete a;
  exit(0);
}

TEST(W1, indexof_clear_test) {
  CS4500_ASSERT_EXIT_ZERO(indexof_clear_test)
}
 
// Tests concat and equals
void concat_equals_test() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = new String("123");
  Object * o = new Object();
  Array * a = new Array(2);
  Array * a2 = new Array(2);
  a->push(s);
  a->push(t);
  a2->push(u);
  a2->push(o);
  Array * a3 = a->concat(a2);
  CS4500_ASSERT_TRUE(a3->indexOf(t) == 1);
  CS4500_ASSERT_TRUE(a3->indexOf(o) == 3);
  CS4500_ASSERT_FALSE(a3->equals(a2));
  CS4500_ASSERT_FALSE(a3->equals(u));
  CS4500_ASSERT_FALSE(a->equals(a2));
  CS4500_ASSERT_TRUE(a3->size() == 4);
  Array * a4 = new Array(4);
  a4->push(s);
  a4->push(t);
  a4->push(u);
  a4->push(o);
  CS4500_ASSERT_TRUE(a3->equals(a4));
  delete s;
  delete t;
  delete u;
  delete o;
  delete a;
  delete a2;
  delete a3;
  delete a4;
  exit(0);
}

TEST(W1, concat_equals_test) { CS4500_ASSERT_EXIT_ZERO(concat_equals_test) }
 
// tests the hashing
void hash_test() {
  String * s = new String("A");
  String * t = new String("B");
  Array * a = new Array(2);
  Array * a2 = new Array(3);
  a->push(s);
  CS4500_ASSERT_FALSE(a->hash() == a2->hash());
  a2->push(s);
  CS4500_ASSERT_TRUE(a->hash() == a2->hash());
  a->push(t);
  CS4500_ASSERT_FALSE(a->hash() == a2->hash());
  a2->push(t);
  CS4500_ASSERT_TRUE(a->hash() == a2->hash());
  delete a;
  delete s;
  delete t;
  exit(0);
}

TEST(W1, hash_test) { CS4500_ASSERT_EXIT_ZERO(hash_test) }

//testing String Array
void push_set_str_array_test() {
  String * s = new String("A");
  String * t = new String("BCD");
  String * e = new String("BCD");
  StringArray * a = new StringArray();
  a->push(s);
  a->push(t);
  CS4500_ASSERT_TRUE(static_cast<String*> (a->get(1))->equals(e));
  a->set(0, t);
  CS4500_ASSERT_TRUE(static_cast<String*> (a->get(0))->equals(t));
  delete a;
  delete s;
  delete t;
  exit(0);
}

TEST(W1, push_set_str_array_test) { CS4500_ASSERT_EXIT_ZERO(push_set_str_array_test) }

// testing Bool Array
void push_set_bool_array_test() {
  BoolArray * a = new BoolArray();
  BoolObj * b1 = new BoolObj(true);
  BoolObj * b2 = new BoolObj(false);
  a->push(b1);
  a->push(b2);
  CS4500_ASSERT_TRUE(static_cast<BoolObj*> (a->get(1))->getBool() == false);
  a->set(0, b2);
  CS4500_ASSERT_TRUE(static_cast<BoolObj*> (a->get(0))->getBool() == false);
  delete a;
  delete b1;
  delete b2;
  exit(0);
}

TEST(W1, push_set_bool_array_test) { CS4500_ASSERT_EXIT_ZERO(push_set_bool_array_test) }

// testing Int Array
void push_set_int_array_test() {
  IntArray * a = new IntArray();
  IntObj * i1 = new IntObj(12);
  IntObj * i2 = new IntObj(2);
  a->push(i1);
  a->push(i2);
  CS4500_ASSERT_TRUE(static_cast<IntObj*> (a->get(1))->getInt() == 2);
  a->set(0, i2);
  CS4500_ASSERT_TRUE(static_cast<IntObj*> (a->get(0))->getInt() == 2);
  delete a;
  delete i1;
  delete i2;
  exit(0);
}


TEST(W1, push_set_int_array_test) { CS4500_ASSERT_EXIT_ZERO(push_set_int_array_test) }

// testing Float Array
void push_set_float_array_test() {
  FloatArray * a = new FloatArray();
  FloatObj * f1 = new FloatObj(1.2);
  FloatObj * f2 = new FloatObj(2.2);
  a->push(f1);
  a->push(f2);
  float epsilon = .01;
  float x = static_cast<FloatObj*> (a->get(1))->getFloat() - 2.2;
  CS4500_ASSERT_TRUE( x < epsilon && x > -epsilon); 
  a->set(0, f2);
  x = static_cast<FloatObj*> (a->get(0))->getFloat() - 2.2;
  CS4500_ASSERT_TRUE( x < epsilon && x > -epsilon); 
  delete a;
  delete f1;
  delete f2;
  exit(0);
}

TEST(W1, push_set_float_array_test) { CS4500_ASSERT_EXIT_ZERO(push_set_float_array_test) }

// tests the resizing
void resize_test() {
  String * s = new String("A");
  String * t = new String("B");
  FloatObj * f = new FloatObj(2.2);
  IntObj * i = new IntObj(2);
  IntObj * i2 = new IntObj(2);
  Array * a = new Array(2);
  a->push(s);
  a->push(t);
  a->push(f);
  a->push(i);
  CS4500_ASSERT_TRUE(a->get(3)->equals(i2));
  delete a;
  delete s;
  delete f;
  delete t;
  delete i;
  delete i2;
  exit(0);
}

TEST(W1, resize_test) { CS4500_ASSERT_EXIT_ZERO(resize_test) }


// test death of get
void death_get() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * x = new String("HelloWorld");
  Array * a = new Array(3);
  a->push(s);
  a->push(t);
  a->push(x);
  a->get(4);
  exit(0);
}

TEST(D1, death_get) { CS4500_ASSERT_EXIT_ONE(death_get) }


// test death of set
void death_set() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * x = new String("HelloWorld");
  Array * a = new Array(3);
  a->push(s);
  a->push(t);
  a->push(x);
  a->set(4, s);
  exit(0);
}

TEST(D1, death_set) { CS4500_ASSERT_EXIT_ONE(death_set) }

void typed_array_death_test_helper_push(Array* arr) {
  String * s = new String("Hello");
  FloatObj * f = new FloatObj(2.2);
  arr->push(s);
  arr->push(f);
}

// tests death of string array with push
void death_push_string_arr_test() {
  StringArray * a = new StringArray();
  typed_array_death_test_helper_push(a);
  exit(0);
}

TEST(D1, death_push_string_arr_test) { CS4500_ASSERT_EXIT_ONE(death_push_string_arr_test) }

// tests death of string array with push
void death_push_bool_arr_test() {
  BoolArray * b = new BoolArray();
  typed_array_death_test_helper_push(b);
  exit(0);
}

TEST(D1, death_push_bool_arr_test) { CS4500_ASSERT_EXIT_ONE(death_push_bool_arr_test) }

// tests death of int array with push
void death_push_int_arr_test() {
  IntArray * i = new IntArray();
  typed_array_death_test_helper_push(i);
  exit(0);
}

TEST(D1, death_push_int_arr_test) { CS4500_ASSERT_EXIT_ONE(death_push_int_arr_test) }

// tests death of float array with push
void death_push_float_arr_test() {
  FloatArray * f = new FloatArray();
  typed_array_death_test_helper_push(f);
  exit(0);
}

TEST(D1, death_push_float_arr_test) { CS4500_ASSERT_EXIT_ONE(death_push_float_arr_test) }

void typed_array_death_test_helper_set(Array* arr) {
  String * s = new String("Hello");
  FloatObj * f = new FloatObj(2.2);
  arr->set(0, s);
  arr->set(1, f);
}

// tests death of string array with set
void death_set_string_arr_test() {
  String * s = new String("A");
  String * t = new String("BCD");
  StringArray * a = new StringArray();
  a->push(s);
  a->push(t);
  typed_array_death_test_helper_set(a);
  exit(0);
}

TEST(D1, death_set_string_arr_test) { CS4500_ASSERT_EXIT_ONE(death_set_string_arr_test) }

// tests death of float array with set
void death_set_float_arr_test() {
  FloatArray * a = new FloatArray();
  FloatObj * f1 = new FloatObj(1.2);
  FloatObj * f2 = new FloatObj(2.2);
  a->push(f1);
  a->push(f2);
  typed_array_death_test_helper_set(a);
  exit(0);
}

TEST(D1, death_set_float_arr_test) { CS4500_ASSERT_EXIT_ONE(death_set_float_arr_test) }

// tests death of int array with set
void death_set_int_arr_test() {
  IntArray * a = new IntArray();
  IntObj * i1 = new IntObj(12);
  IntObj * i2 = new IntObj(2);
  a->push(i1);
  a->push(i2);
  typed_array_death_test_helper_set(a);
  exit(0);
}

TEST(D1, death_set_int_arr_test) { CS4500_ASSERT_EXIT_ONE(death_set_int_arr_test) }

 // tests death of bool array with set
void death_set_bool_arr_test() {
  BoolArray * a = new BoolArray();
  BoolObj * b1 = new BoolObj(true);
  BoolObj * b2 = new BoolObj(false);
  a->push(b1);
  a->push(b2);
  typed_array_death_test_helper_set(a);
  exit(0);
}

TEST(D1, death_set_bool_arr_test) { CS4500_ASSERT_EXIT_ONE(death_set_bool_arr_test) }

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}