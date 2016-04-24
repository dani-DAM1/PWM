class PWM{
	public:
		PWM(int pin);
		int handler();
		int getCounter();
		void setDuty(int dutyCicle);
		void setRetard(unsigned long retard);
	private:
		int _pin;
		int _dutyCicle;
		int _counter;
		unsigned long _retard;
		unsigned long _tempActual;
		unsigned long _tempVell;
};
