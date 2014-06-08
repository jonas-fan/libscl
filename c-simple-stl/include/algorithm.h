#ifndef ALGORITHM_H_
#define ALGORITHM_H_

/**
 *    Simple Algorithms
 *
 *    @version 0.0.1
 *    @date    2014/06/08
 *    @author  Jian <jianfan.tw@gmail.com>
 */

void sort(void **data, const unsigned int length, int (*compare)(const void *, const void *));

#endif  // ALGORITHM_H_