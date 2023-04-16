#include "snake.h"
#include <conio.h>
#include "tools.h"
#include <iostream>


void Snake::InitSnake()
{
	//初始化贪吃蛇
	for (auto& point : snake) 
	{
		point.PrintCircular();
	}
}


//蛇移动
void Snake::Move()
{
	switch (direction)
	{
	case Direction::UP:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1));
		break;
	case Direction::DOWN:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() +1));
		break;
	case Direction::LEFT:
		snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY()));
		break;
	case Direction::RIGHT:
		snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
		break;
	default:
		break;
	}
	SetColor(14);
	snake.back().PrintCircular();
	
}

//蛇正常移动，头增长，尾缩短
void Snake::NormalMove()
{
	Move();
	snake.front().Clear();
	snake.pop_front();
}


//超出边界
bool Snake::OverEdge()
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}

//撞到自身
bool Snake::HitItself() 
{
	std::deque<Point>::size_type cnt = 1;
	//获取头部坐标
	Point* head = new Point(snake.back().GetX(), snake.back().GetY());
	//如果整条蛇中蛇头不相同的坐标不等于蛇长，则意味着蛇头碰撞到自身
	for (auto& point : snake)
	{
		if (!(point == *head))
		{
			++cnt;
		}
		else
		{
			break;
		}
	}
		delete head;
		if(cnt==snake.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	
}



//改变方向
bool Snake::ChangeDirection()
{
	char ch;
	if (_kbhit())//kbhit函数返回值为两个，需注意
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (direction != Direction::DOWN)//如果按键方向与移动方向相反，无效
				{
					direction = Direction::UP;
				}
				break;
			case 80:
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75:
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77:
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;
		case 27://ESC
			return false;
		default:
			return true;
		}
	}
	return true;
}



//吃到食物
bool Snake::GetFood(const Food& cfood)
{
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y) {
		return true;
	}
	else 
	{
		return false;
	}

}

//吃到限时食物
bool Snake::GetBigFood(Food& cfood)
{
	if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
	{
		cfood.big_flag = false;
		cfood.big_x = 0;
		cfood.big_y = 0;
		SetCursorPosition(1, 0);
		std::cout << "                                                           ";
		return true;
	}
	else 
	{
		return false;
	}
}
