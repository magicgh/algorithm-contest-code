struct Queue
{
	int head,tail,q[500005];
	Queue(){head=1,t=1;return;}
	inline void push(int x){q[++tail]=x;}
	inline void pop(){head++;}
	inline bool empty(){return head>=tail||head<0||tail<0;}
	inline int top(){return q[head];}
	inline int back(){return q[tail];}
};
