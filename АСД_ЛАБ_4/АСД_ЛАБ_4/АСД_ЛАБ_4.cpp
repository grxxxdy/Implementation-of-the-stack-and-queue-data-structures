#include <iostream>
#include <iomanip>

#define N 5

using namespace std;

struct webPage
{
	string url;
	int urlSize;
	bool isSecure;
};

struct history
{
	webPage web[N];

	int topIndex = -1;


	bool push(string url, int urlSize, bool security)
	{
		if (topIndex < N - 1)
		{
			topIndex++;

			web[topIndex] = { url, urlSize, security };

			return true;
		}
		else
		{
			return false;
		}
	}

	bool pop()
	{
		if (topIndex > 0)
		{
			topIndex--;
			return true;
		}
		else
		{
			return false;
		}
	}

	webPage top()
	{
		return web[topIndex];
	}
};

void task1()
{
	history his;					// 1)

	webPage currentWeb, topWeb;

	cout << "History size: " << his.topIndex + 1 << endl;

	cout << "Adding 4 pages to the history." << endl;		// 2)

	for (int i = 0; i < 4; i++)
	{
		cout << "\nEnter page url: ";
		cin >> currentWeb.url;

		currentWeb.urlSize = 10 + rand() % 91;

		currentWeb.isSecure = rand() % 2;
		if (!his.push(currentWeb.url, currentWeb.urlSize, currentWeb.isSecure))
		{
			cout << "Stack is full, can`t add another element";
			break;
		}
		else
		{
			topWeb = his.top();

			cout << "History size: " << his.topIndex + 1 << "\nLast history element (url, size, security): " << topWeb.url << "\t" << topWeb.urlSize << " Kb\t" << topWeb.isSecure << endl;
		}
	}

	cout << "\nEnabling safe connection for the page and adding it to the history." << endl;		// 3)

	currentWeb.isSecure = 1;

	if (!his.push(currentWeb.url, currentWeb.urlSize, currentWeb.isSecure))
	{
		cout << "Stack is full, can`t add another element";
	}
	else
	{
		topWeb = his.top();

		cout << "History size: " << his.topIndex + 1 << "\nLast history element (url, size, security): " << topWeb.url << "\t" << topWeb.urlSize << " Kb\t" << topWeb.isSecure << endl;
	}

	cout << "\nAdding another 3 pages to the history." << endl;

	for (int i = 0; i < 3; i++)							// 4)
	{
		cout << "\nEnter page url: ";
		cin >> currentWeb.url;
		currentWeb.urlSize = 10 + rand() % 91;
		currentWeb.isSecure = rand() % 2;
		if (!his.push(currentWeb.url, currentWeb.urlSize, currentWeb.isSecure))
		{
			cout << "Stack is full, can`t add another element";
			break;
		}
		else
		{
			topWeb = his.top();

			cout << "History size: " << his.topIndex + 1 << "\nLast history element (url, size, security): " << topWeb.url << "\t" << topWeb.urlSize << " Kb\t" << topWeb.isSecure << endl;
		}
	}

	cout << endl;

	cout << "\nDeleting 1 page." << endl;			// 5)

	if (his.pop())
	{
		topWeb = his.top();
		cout << "History size: " << his.topIndex + 1 << endl;
		if (his.topIndex > 0)
		{
			cout << "Last history element (url, size, security) : " << topWeb.url << "\t" << topWeb.urlSize << " Kb\t" << topWeb.isSecure << endl;
		}
	}
	else
	{
		cout << "Stack is empty.";
	}

	cout << "\nDeleting another 5 pages." << endl;			// 6)

	for (int i = 0; i < 5; i++)
	{
		if (his.pop())
		{
			topWeb = his.top();
			cout << "\nHistory size: " << his.topIndex + 1 << endl;
			if (his.topIndex + 1 > 0)
			{
				cout << "Last history element (url, size, security) : " << topWeb.url << "\t" << topWeb.urlSize << " Kb\t" << topWeb.isSecure << endl;
			}
		}
		else
		{
			cout << "\nStack is empty." << endl;
		}
	}
}

struct article
{
	string name;
	float price;
	int expDate;
};

struct queue
{
	article art[N];

	int head = 0, tail = -1, queueElements = 0;

	bool push(string name, float price, int days)
	{
		if ((tail + 1) % N == 1 && head > 0 && queueElements < N)
		{
			tail = 0;
			queueElements++;
		}
		else if (tail < N - 1 && queueElements < N)
		{
			tail++;
			queueElements++;
		}
		else
		{
			return 0;
		}

		art[tail] = { name,price,days };

		return 1;
	}

	bool pop()
	{
		if (head < N - 1 && queueElements >= 0)
		{
			head++;
			queueElements--;
		}
		else if ((head + 1) % N == 1 && queueElements >= 0)
		{

			head = 0;
			queueElements--;
		}
		else
		{
			return 0;
		}

		return 1;
	}

	article front()
	{
		return art[head];
	}

};

void task2()
{
	article currentArt, frontArt, lastArt;				// 1)

	queue shopQueue;

	cout << "Queue size: " << shopQueue.queueElements << endl;

	cout << "\n\Adding 3 products on the checkout belt." << endl;					// 2)

	for (int i = 0; i < 4; i++)
	{
		cout << "\nEnter product name: ";
		cin >> currentArt.name;

		currentArt.price = (10 + rand() % 91) + (1 + rand() % 99) * 0.01;

		currentArt.expDate = 1 + rand() % 30;

		if (!shopQueue.push(currentArt.name, currentArt.price, currentArt.expDate))
		{
			cout << "Queue is full, cannot add another product." << endl;
			break;
		}
		else
		{
			frontArt = shopQueue.front();
			lastArt = currentArt;

			cout << "Queue size: " << shopQueue.queueElements << "\nFirst element in queue (product name, price, expiration date): " << frontArt.name << "\t" << frontArt.price << " hrn\t" << frontArt.expDate << " days" << endl;
			cout << "Last element in queue (product name, price, expiration date): " << lastArt.name << "\t" << lastArt.price << " hrn\t" << lastArt.expDate << " days" << endl;
		}
	}

	cout << "\n\nApplying a 25% discount on the product: " << frontArt.name << endl;			// 3)

	frontArt.price = frontArt.price * 0.75;

	cout << "Queue size: " << shopQueue.queueElements << "\nFirst element in queue (product name, price, expiration date): " << frontArt.name << "\t" << setprecision(4) << frontArt.price << " hrn\t" << frontArt.expDate << " days" << endl;
	cout << "Last element in queue (product name, price, expiration date): " << currentArt.name << "\t" << currentArt.price << " hrn\t" << currentArt.expDate << " days" << endl;

	cout << "\n\nAdding 3 more products on the checkout belt." << endl;				// 4)

	for (int i = 0; i < 3; i++)
	{
		cout << "\nEnter product name: ";
		cin >> currentArt.name;

		currentArt.price = (10 + rand() % 91) + (1 + rand() % 99) * 0.01;

		currentArt.expDate = 1 + rand() % 30;

		if (!shopQueue.push(currentArt.name, currentArt.price, currentArt.expDate))
		{
			cout << "Queue is full, cannot add another product." << endl;;
			break;
		}
		else
		{
			frontArt = shopQueue.front();
			lastArt = currentArt;

			cout << "Queue size: " << shopQueue.queueElements << "\nFirst element in queue (product name, price, expiration date): " << frontArt.name << "\t" << frontArt.price << " hrn\t" << frontArt.expDate << " days" << endl;
			cout << "Last element in queue (product name, price, expiration date): " << lastArt.name << "\t" << lastArt.price << " hrn\t" << lastArt.expDate << " days" << endl;
		}
	}

	cout << "\n\nRemoving 3 products from the checkout belt." << endl;			// 5)

	for (int i = 0; i < 3; i++)
	{
		if (!shopQueue.pop())
		{
			cout << "\nQueue is empty, there is nothing to be removed." << endl;
			break;
		}
		else
		{
			frontArt = shopQueue.front();

			cout << "\nQueue size: " << shopQueue.queueElements << "\nFirst element in queue (product name, price, expiration date): " << frontArt.name << "\t" << frontArt.price << " hrn\t" << frontArt.expDate << " days" << endl;
			cout << "Last element in queue (product name, price, expiration date): " << lastArt.name << "\t" << lastArt.price << " hrn\t" << lastArt.expDate << " days" << endl;
		}
	}

	cout << "\n\nRemoving 4 more products from the checkout belt." << endl;			// 6)

	for (int i = 0; i < 4; i++)
	{
		if (!shopQueue.pop())
		{
			cout << "\nQueue is empty, there is nothing to be removed." << endl;
			break;
		}
		else
		{
			frontArt = shopQueue.front();

			cout << "\nQueue size: " << shopQueue.queueElements << "\nFirst element in queue (product name, price, expiration date): " << frontArt.name << "\t" << frontArt.price << " hrn\t" << frontArt.expDate << " days" << endl;
			cout << "Last element in queue (product name, price, expiration date): " << lastArt.name << "\t" << lastArt.price << " hrn\t" << lastArt.expDate << " days" << endl;
		}
	}

}

struct stack
{
	static const int S = 255;
	char array[S];
	int top = -1;

	bool push(char x)
	{
		if (top < S - 1)
		{
			top++;
			array[top] = x;
			return true;
		}

		return false;
	}

	bool pop()
	{
		if (top > -1)
		{
			top--;
			return true;
		}

		return false;
	}

	char topValue()
	{
		return array[top];
	}

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void task3()
{
	stack bracketsStack;

	string one;
	cin >> one;

	int symbolsAmount = one.length();
	bool error = false;

	for (int i = 0; i < symbolsAmount; i++)
	{
		if (one[i] == '(' || one[i] == '[' || one[i] == '{')
		{
			bracketsStack.push(one[i]);
		}
		else if (one[i] == ')')
		{
			if (bracketsStack.topValue() == '(')
			{
				bracketsStack.pop();
			}
			else
			{
				error = true;
			}
		}
		else if (one[i] == ']')
		{
			if (bracketsStack.topValue() == '[')
			{
				bracketsStack.pop();
			}
			else
			{
				error = true;
			}
		}
		else if (one[i] == '}')
		{
			if (bracketsStack.topValue() == '{')
			{
				bracketsStack.pop();
			}
			else
			{
				error = true;
			}
		}
	}

	if (!bracketsStack.isEmpty() || error)
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}

}

int main()
{
	srand(time(NULL));

	int choice;

	while (true)
	{
		cout << "Choose a task or enter 0 to exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		default:
			cout << "Enter a valid number" << endl;
			break;
		}
	}
}

