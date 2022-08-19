#ifndef TYPES_H
#define TYPES_H

typedef enum { true, false } bool;

typedef void (*T_Singleton_v_v)(void*);
typedef void (*T_Tuple_v_v)(void*, void*);
typedef void (*T_Triple_v_v)(void*, void*, void*);

typedef int (*T_Singleton_i_i)(int);
typedef int (*T_Tuple_i_i)(int, int);
typedef int (*T_Triple_i_i)(int, int, int);

typedef float (*T_Singleton_i_f)(int);
typedef float (*T_Tuple_i_f)(int, int);
typedef float (*T_Triple_i_f)(int, int, int);

typedef float (*T_Singleton_f_f)(float);
typedef float (*T_Tuple_f_f)(float, float);
typedef float (*T_Triple_f_f)(float, float, float);

#endif

