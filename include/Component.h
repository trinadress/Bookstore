#ifndef _COMPONENT_H_
#define _COMPONENT_H_

class Component {
	public:
		Component() {};
		virtual ~Component() {};

		virtual void add(Component *comp) = 0;
};


#endif
