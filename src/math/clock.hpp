#pragma once

namespace sf { class Clock; }

class Clock{
private:
	sf::Clock *impl;
public:
	Clock();
	~Clock();

	Clock(const Clock&) = delete;
	Clock& operator=(const Clock&) = delete;

	float restart();
	float elapsed() const;
};
