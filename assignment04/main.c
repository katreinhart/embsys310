#include <assert.h>
#include "stack.h"


int main()
{
  int result = 0;
  int testInt = 0;
  int numbers[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  
  // TEST CASE 1: Retrieve from empty stack 
  // given:
  
  // when:
  stack_init();
  result = stack_pop(&testInt);
  
  // then:
  assert(-1 == result); // Retrieve failed
  assert(0 == testInt); // Test int is unmodified
  
  // TEST CASE 2: Successfully retrieve from stack
  stack_init();
  
  // given: 
  int firstNum = 2;
  int secondNum = 3;
  result = stack_push(firstNum);
  
  // when:
  result = stack_pop(&secondNum);
  
  // then:
  assert(2 == secondNum); // correct int was retrieved
  assert(0 == result); // operation was successful
  
  // TEST CASE 3: Fill stack, then get all items
  
  // given:
  stack_init();
  
  // when:
  for(int i=0; i < 16; i++) {
    result = stack_push(numbers[i]);
    assert(0== result); // all pushes should be successful
  }
  
  // then:
  int popped;
  for(int i=0; i < 16; i++) {
    result = stack_pop(&popped);
    assert(0 == result); // pop was successful
    assert(numbers[15-i] == popped); // correct int was retrieved (in reverse order)
  }
  
  
  // TEST CASE 4: Fill the stack, then try to add one more item
  // given:
  stack_init();
  for(int i=0; i <= 16; i++) {
    result = stack_push(numbers[i]);
    assert(0 == result);
  }
  
  // when:
  result = stack_push(17);
  
  // then:
  assert(-1 == result); // operation should fail

  // TEST CASE 5: Fill the stack, pop an item, then push another item
  // given: 
  stack_init();
  for(int i=0; i < 16; i++) {
    result = stack_push(numbers[i]);
    assert(0 == result);
  }
  
  // when: 
  result = stack_pop(&testInt);
  assert(0 == result); // pop should succeed
  
  // then:
  result = stack_push(20);
  result = stack_pop(&testInt);
  assert(0 == result);
  assert(20 == testInt);
  
  // TEST CASE 6: Fill and retrieve all items twice in a row.
  // given:
  stack_init();
  for(int i=0; i < 16; i++) {
    result = stack_push(numbers[i]);
    assert(0 == result);
  }
  
  // when:
  for(int i=0; i < 16; i++) {
    result = stack_pop(&popped);
    assert(0 == result); // pop was successful
    assert(numbers[15-i] == popped); // correct int was retrieved (in reverse order)
  }
  
  for(int i=0; i < 16; i++) {
    result = stack_push(numbers[i]);
    assert(0 == result);
  }
  
  for(int i=0; i < 16; i++) {
    result = stack_pop(&popped);
    assert(0 == result); // pop was successful
    assert(numbers[15-i] == popped); // correct int was retrieved (in reverse order)
  }
}
