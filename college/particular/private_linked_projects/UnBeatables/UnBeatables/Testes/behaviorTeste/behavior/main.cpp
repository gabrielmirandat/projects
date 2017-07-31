#include <iostream>
#include <includeMapBehavior.hpp>

int main()
{
  BehaviorBase *current;
  // Initial Behavior Defined At Start
  current = jhonantansViado::Behavior();

  while(true)
  {
    current->action();
    current = current->transition();
  }

  return 0;
}
