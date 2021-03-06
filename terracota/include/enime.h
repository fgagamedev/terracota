#ifndef ENIME_H
#define ENIME_H

#include <core/object.h>
#include <core/animation.h>

using std::unique_ptr;
using std::pair;

class Life;

class Enime: public Object
{
public:
	Enime(Object* parent,ObjectID id,int time,int radius,int speed,int force);
	~Enime();
	void set_animation(const string& file,double x,double y,
					   double w,double h, double n_frame, 
					   double frame_rate,bool animate,int rows);
	void set_die_animation(const string& file,double x,double y,
					   double w,double h, double n_frame, 
					   double frame_rate,bool animate,int rows);
	Life* get_life();

	void set_has_key(bool key);
	bool has_key();
	void damage(int life);
	void update_self(unsigned long elapsed);
	void draw_self();
    void follow_main_char();
	int force();
	void die();
	bool can_attack();
	void set_can_attack(bool can);
private:
    Life* m_life;
    Animation* m_animation;
    Animation* m_die_animation;
	unsigned long m_start,m_time;
	int m_radius,m_speed;
	bool m_allow_attack;
	int m_rows;
	int m_rows_die;
	bool m_key;
	int m_force;
};

#endif
