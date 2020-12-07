#ifndef _GROUP_H_
#define _GROUP_H_

#include "Component.h"
#include <vector>

class Group : public Component {
	public:
		Group();

		void add(Component *children);

	private:
		std::vector<Component *> children;

};

#endif
