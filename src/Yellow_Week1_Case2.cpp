//============================================================================
// Name        : Yellow_Week1_Case2.cpp
// Author      : grec88
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Block {
private:
	int den;
	int w, h, d;
	uint64_t  m;

public:

	Block() {
		den = 0;
		w = 0;
		h = 0;
		d = 0;
		m = 0;
	}

	Block(const int &den, const int &w, const int &h,
			const int &d) {
		this->den = den;
		this->w = w;
		this->h = h;
		this->d = d;
		ChangeM();
	}

	uint64_t GetM() const {
		return m;
	}

	void SetDen(const int& den){
		this->den = den;
		ChangeM();
	}

	void ChangeM(){
		this->m = static_cast<uint64_t>(den) * w * h * d;
	}
};

istream& operator>>(istream &stream, Block &block) {
	int w = 0, h = 0, d = 0;
	if (stream) {
		stream >> w >> h >> d;
		if (stream) {
			block = Block(0, w, h, d);
		}
	}
	return stream;
}



int main() {
	size_t n = 0;
	int den = 0;
	cin >> n >> den;
	vector<Block> blocks(n);
	uint64_t m_sum = 0;
	for(auto& c : blocks){
		cin >> c;
		c.SetDen(den);
		m_sum += c.GetM();
	}
	cout << m_sum << endl;
	return 0;
}
