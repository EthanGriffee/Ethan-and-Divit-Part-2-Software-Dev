#include "object.h"  
#include "string.h"  
#include "array.h"    
#include "helper.h"
 
void FAIL() {   exit(1);    }
void OK(const char* m) { println(m);}
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }
 
// Tests setting, getting, and size
void test1() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * x = new String("HelloWorld");
  Array * a = new Array(3);
  a->set(0, s);
  a->set(1, t);
  a->set(2, x);
  t_true(a->get(2)->equals(x));
  t_true(a->get(1)->equals(t));
  t_true(a->size() == 2);
  a->set(1, s);
  t_true(a->get(1)->equals(s));
  delete s;
  delete t;
  delete x;
  delete a;
  OK("1");
}
 
// Tests indexOf and clear
void test2() {
  String * s = new String("Hello");
  String * t = new String("World");
  Object * u = new Object();
  Array * a = new Array(3);
  a->set(0, s);
  a->set(1, t);
  a->set(2, u);
  t_true(a->indexOf(t) == 1);
  t_true(a->indexOf(s) == 0);
  t_true(a->indexOf(s, 1) == -1);
  a->set(2, s);
  t_true(a->indexOf(s, 1) == 2);
  a->clear();
  t_true(a->indexOf(t) == -1);
  delete s;
  delete t;
  delete u;
  delete a;
  OK("2");
}
 
// Tests concat and equals
void test3() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = new String("123");
  Object * o = new Object();
  Array * a = new Array(2);
  Array * a2 = new Array(2);
  a->set(0, s);
  a->set(1, t);
  a2->set(0, u);
  a2->set(1, o);
  Array * a3 = a->concat(a2);
  t_true(a3->indexOf(t) == 1);
  t_true(a3->indexOf(u) == 3);
  t_false(a3->equals(a2));
  t_false(a3->equals(u));
  t_false(a->equals(a2));
  t_true(a3->size() == 4);
  Array * a4 = new Array(4);
  a4->set(0, s);
  a4->set(1, t);
  a4->set(2, u);
  a4->set(3, o);
  t_true(a3->equals(a4));
  delete s;
  delete t;
  delete u;
  delete o;
  delete a;
  delete a2;
  delete a3;
  delete a4;
  OK("3");
}
 
// tests the hashing
void test4() {
  String * s = new String("A");
  String * t = new String("B");
  Array * a = new Array(2);
  a->set(0, s);
  t_true(a->hash() == s->hash());
  a->set(1, t);
  t_true(a->hash() == s->hash() + t->hash());
  delete a;
  delete s;
  delete t;
  OK("4");
}

//testing String Array
void test5() {
  String * s = new String("A");
  String * t = new String("BCD");
  StringArray * a = new StringArray();
  a->push(s);
  a->push(t);
  t_true(static_cast<String*> (a->get(1))->length() == 3);
  delete a;
  delete s;
  delete t;
}

// testing Bool Array
void test6() {
  BoolArray * a = new BoolArray();
  BoolObj * b1 = new BoolObj(true);
  BoolObj * b2 = new BoolObj(false);
  a->push(b1);
  a->push(b2);
  t_true(static_cast<BoolObj*> (a->get(1))->getBool() == true);
  delete a;
  delete b1;
  delete b2;
}

// testing Int Array
void test7() {
  IntArray * a = new IntArray();
  IntObj * i1 = new IntObj(12);
  IntObj * i2 = new IntObj(2);
  a->push(i1);
  a->push(i2);
  t_true(static_cast<IntObj*> (a->get(1))->getInt() == 2);
  delete a;
  delete i1;
  delete i2;
}

// testing Float Array
void test8() {
  FloatArray * a = new FloatArray();
  FloatObj * f1 = new FloatObj(1.2);
  FloatObj * f2 = new FloatObj(2.2);
  a->push(f1);
  a->push(f2);
  t_true(static_cast<FloatObj*> (a->get(1))->getFloat() == 2.2); 
  delete a;
  delete f1;
  delete f2;
}

// tests the resizing
void test4() {
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
  t_true(a->get(3)->equals(i2));
  delete a;
  delete s;
  delete f;
  delete t;
  delete i;
  delete i2;
  OK("4");
}

 
int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}