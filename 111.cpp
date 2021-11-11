// 编写程序，输入两个字符串string1和string2，检查在string1中是否包含有string2，
// 如果有，则输出string2在string1中的起始位置；如果没有，则显示“NO”；如果string2在
// string1中多次出现，则输出在string1中出现的次数以及每次出现的起始位置，例如：
// 	string1="the day the month the year";
// 	string2="the"
// 输出结果应为：出现三次，起始位置分别是：0,8,18。
// 又如：
// 	string1="aaabacad"
// 	string2="a"
// 输出结果应为：出现五次，起始位置分别是：0,1,2,4,6。

// 输入输出格式要求：
// 	输入格式：string1回车string2回车
// 例如：
// 输入：the day the month the year回车the回车
// 输出：3times,0,8,18
// 输入：aaabacad回车a回车
// 输出：5times,0,1,2,4,6
// 输入：aaabacad回车e回车
// 输出：NO