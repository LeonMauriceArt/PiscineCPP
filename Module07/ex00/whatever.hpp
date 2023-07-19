#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T> void swap(T &param1, T &param2)
{
    T buff = param1;
    param1 = param2;
    param2 = buff;
	return;
}

template <typename T> T min(T param1, T param2)
{
	if (param1 < param2)
		return(param1);
	else if (param2 < param1)
		return(param2);
	else
		return (param2);
}

template <typename T> T max(T param1, T param2)
{
	if (param1 > param2)
		return(param1);
	else if (param2 > param1)
		return(param2);
	else
		return (param2);
}

#endif