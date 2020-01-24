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
  t_true(a3->size == 4);
  Array * a4 = new Array(4);
  a4->set(0, s);
  a4->set(1, t);
  a4->set(2, u);
  a4->set(3, o);
  t_true(a3->equals(a4));
  OK("3");
}
 
// tests the hashing
void test4() {
  String * s = new String("A");
  String * t = new String("B");
  Array * a = new Array(2);
  a->set(0, s);
  t_true(a->hash() == 65);
  a->set(1, t);
  t_true(a->hash() == 131);
  OK("4");
}

 
int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}