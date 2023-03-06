// use namespace std;

#include "socket.hpp"

class Block
{
	private:

		Block();
		Block(size_t index, size_t timestamp, size_t block_hash, size_t prev_block_hash, size_t transactions);
		~Block();


	public:

		size_t	index;
		size_t	timestamp;
		size_t	block_hash;
		size_t	prev_block_hash;
		string	transactions;
};

Block::Block(size_t index, size_t timestamp, size_t block_hash, size_t prev_block_hash, size_t transactions)
{
	this->index = index;
	this->timestamp = timestamp;
	this->block_hash = block_hash;
	this->prev_block_hash = prev_block_hash;
	this->transactions = transactions;
}

