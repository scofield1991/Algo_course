#include <iostream>

int get_change(int m) {
  
  int num_coins = 0;
  int last_change = 0;
  int cur_change = 0;

  while(m > 0)
  {
  	if(m >= 10)
  	{
  		m -= 10;
  		num_coins++;
  	}
  	else if(m >= 5)
  	{
  		m -= 5;
  		num_coins++;
  	}
  	else if(m >= 1)
  	{
  		m -= 1;
  		num_coins++;
  	}

  }

  return num_coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
