#ifndef __LOGGING_FORMAT_H__
#define __LOGGING_FORMAT_H__

/*
 * Each LOLog line has a fixed arity followed by a matching number of words
 * representing the data.
 */
struct lol_line {
	unsigned int arity;
	unsigned int data[0];
};

struct lol_output {
	char cookie[3]; /* The magic "LOL" that marks this format */
	unsigned int count;
	struct lol_line lines[0];
};

#endif
