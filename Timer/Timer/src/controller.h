#pragma once


class Controller {
public:
	Controller() :speed(200), key(1), score(0) {}
	void Start();
	void Select();
	void DrawGame();
	int PlayGame();
	void UpdateScore(const int&);
	void RewriteScore();
	int Menu();
	void Game();
	int GameOver();

private:
	//速度
	int speed;
	//按键
	int key;
	//分数
	int score;
};