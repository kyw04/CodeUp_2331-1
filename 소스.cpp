#include <iostream>
using namespace std;

string str_day[] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
int month_day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
int main()
{
	int year = 2100, month = 1, day = 1;
	int total_day, i;
	int a, b, c, maximum;
	cin >> a >> b >> c;

	maximum = a > b ? a : b;
	maximum = maximum > c ? maximum : c;

	int temp_max = maximum;
	int temp_a = a + day, temp_b = b + day, temp_c = c + day;
	while (temp_a != temp_b || temp_b != temp_c)
	{
		while (temp_a < maximum) temp_a += a;
		while (temp_b < maximum) temp_b += b;
		while (temp_c < maximum) temp_c += c;
		maximum += temp_max;
	}
	total_day = temp_a;
	day = total_day;
	

	while (total_day > 365 - 31)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			total_day--;
		year++;
		total_day -= 365 - 31;
	}
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		month_day[1] = 29;
	for (i = 0; i < 11; i++)
	{
		if (total_day <= month_day[i])
		{
			month = i + 1;
			break;
		}
		total_day -= month_day[i];
	}
	if (i == 12)
		month = 11;

	printf("%04d-%02d-%02d ", year, month, total_day);
	cout << str_day[day % 7];
	return 0;
}