//#include <wiringPi.h>
//#include <softPwm.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

int EchoPin = 30;             //Define the EchoPin connect to wiringPi port 30 of Raspberry pi
int TrigPin = 31;             //Define the TrigPin connect to wiringPi port 31 of Raspberry pi

/**
* Function       Distance
* @author        Danny
* @date          2017.08.16
* @brief         measure the distance by Ultrasonic
* @param[in]     void
* @param[out]    void
* @retval        float:distance
* @par History
*/
float Distance()
{
	float distance;
	struct timeval tv1;
	struct timeval tv2;
	struct timeval tv3;
	struct timeval tv4;
	long start, stop;
	digitalWrite(TrigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(TrigPin, HIGH);       //Input a high level of at least 10 US to the Trig pin
	delayMicroseconds(15);
	digitalWrite(TrigPin, LOW);

	gettimeofday(&tv3, NULL);

	start = tv3.tv_sec * 1000000 + tv3.tv_usec;
	while(!digitalRead(EchoPin) == 1)
	{
		gettimeofday(&tv4, NULL);
		stop = tv4.tv_sec * 1000000 + tv4.tv_usec;
		if ((stop - start) > 30000)  //Maximum time value (5m)：10/340=0.03s
		{
			return -1;
		}
	}

 	gettimeofday(&tv1, NULL);
        start = tv1.tv_sec*1000000+tv1.tv_usec;
	while(!digitalRead(EchoPin) == 0)
	{
		gettimeofday(&tv3,NULL);
		stop = tv3.tv_sec*1000000+tv3.tv_usec;
		if ((stop - start) > 30000)
		{
			return -1;
		}
	}
	gettimeofday(&tv2, NULL);

	start = tv1.tv_sec * 1000000 + tv1.tv_usec;
	stop = tv2.tv_sec * 1000000 + tv2.tv_usec;

	distance = (float)(stop - start)/1000000 * 34000 / 2;
	return distance;
}

/**
* Function       bubble
* @author        Danny
* @date          2017.08.16
* @brief         Bubble sorting
* @param[in1]    a:Ultrasonic array first address
* @param[in2]    n:Size of Ultrasonic array
* @param[out]    void
* @retval        void
* @par History
*/
void bubble(unsigned long *a, int n)

{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (a[i] > a[j])
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

/**
* Function       Distane_test
* @author        Danny
* @date          2017.08.16
* @brief         Remove the maximum, minimum of the 5 datas, and get average values of 3 datas to improve accuracy of test
* @param[in]     void
* @param[out]    void
* @retval        float:distance
* @par History
*/
float Distance_test()
{
  float distance;
  unsigned long ultrasonic[5] = {0};
  int num = 0;
  while (num < 5)
  {
     distance = Distance();
	 while((int)distance == -1)
	 {
		 distance = Distance();
	 }
    //Filter out data greater than 500 or smaller than 0 in the test distance
    while ( (int)distance >= 500 || (int)distance == 0)
    {
         distance = Distance();
    }
    ultrasonic[num] = distance;
    num++;
	delay(10);
  }
  num = 0;
  bubble(ultrasonic, 5);
  distance = (ultrasonic[1] + ultrasonic[2] + ultrasonic[3]) / 3;

  return distance;
}

/**
* Function       main
* @author        Danny
* @date          2017.08.16
* @brief         When key is pressed, Ultrasonic obstacle avoidance mode is opened
* @param[in]     void
* @retval        void
* @par History
*/
int main()
{
  using namespace std;
  float distance;
  std::cout << "Hello from C++ program!" << std::endl;
  //Initialize wiringPi
  wiringPiSetup();

  //Initialize ultrasonic pin
  pinMode(EchoPin, INPUT);
  pinMode(TrigPin, OUTPUT);

  while(1)
  {
   delay(5000);
   distance = Distance_test();
   printf("%f\n",distance);
 }
 return 0;
}

