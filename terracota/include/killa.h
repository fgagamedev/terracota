#ifndef H_KILLA_H
#define H_KILLA_H

#include <core/sprite.h>

using std::unique_ptr;
using std::pair;

class Life;
class Killa: public Sprite
{
public:
    typedef enum { NONE, IDLE, WALKING,ATTACKING, INTERACTING } State;
    typedef enum { MOVED, STOPPED,ATTACKED,CHANGING,INTERACTED } Event;
    typedef enum { LEFT, RIGHT ,UP,DOWN } Direction;

	Killa(Object* parent,const string& id);
	~Killa();


	Direction direction() const;
	void set_direction(Direction direction);
	const pair<double,double>& moviment() const;
	void set_moviment(double xaxis,double yaxis);
	Life* life();
	bool can_change();
private:
	class Impl;
	unique_ptr<Impl> m_impl;
};

#endif
