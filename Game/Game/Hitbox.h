#pragma once
class Hitbox
{
private:
	int W, H, X, Y;
	bool Collide;
	/*
	______   T is Top, W is Width
	|     |
	|     |
	|_____|  
	
	X and Y are set at the lower left corner
	*/
public:
	Hitbox(int width, int height, int xin, int yin, bool collision);
	~Hitbox();
	int getPos() {
		return X, Y;
	}
	int getCollide() {
		return Collide;
	}
	int getWidth() {
		return W;
	}
	int getHeight() {
		return H;
	}
	bool isOverlapping(Hitbox O) {
		bool overlap = false;
		int Ox, Oy = O.getPos();
		int Ow = O.getWidth();
		int Oh = O.getHeight();
		int Ors = Ox + Ow;
		int Ot = Oy + Oh;
		int RS = X + W;
		int T = Y + H;
		bool vertical, horizontal;

		if (((Ot >= Y) && (Oy <= Y)) || ((T >= Oy) && (Y <= Oy))) {
			vertical = true;
		}
		else {
			vertical = false;
		}
		if (((Ors >= X) && (Ox <= X)) || ((RS >= Ox) && (X <= Ox))) {
			horizontal = true;
		}
		else {
			horizontal = false;
		}
		overlap = (vertical&&horizontal);
		return overlap;
	}
	bool isColliding(Hitbox O) {
		bool hit = false;
		bool coll = O.getCollide();
		bool overlap = isOverlapping(O);
		coll = (coll&&Collide);
		hit = (coll&&overlap);
		return hit;
	}
};

