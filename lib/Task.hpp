# ifndef _Task_hpp
# define _Task_hpp


class Task {

	private:
		volatile int state;
		volatile int counter;
	
	protected:
		void setNextState(int state,int delay);
		void setNextState(int state);
		
	public:
		Task();
		void tick();
		void loop();
		virtual void callState(int state) = 0;
		
}; // class Task
# endif
