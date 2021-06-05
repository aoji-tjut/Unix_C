class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<double> small;
    priority_queue<double, vector<double>, greater<double>> big;
    int size;

    MedianFinder()
    {
        size = 0;
    }

    void addNum(int num)
    {
        size++;

        if(small.empty())
        {
            small.push(num);
            return;
        }

        if(num < small.top())
        {
            small.push(num);
        }
        else
        {
            big.push(num);
        }

        if(small.size() - big.size() == 2)
        {
            big.push(small.top());
            small.pop();
        }

        if(big.size() - small.size() == 2)
        {
            small.push(big.top());
            big.pop();
        }
    }

    double findMedian()
    {
        if(size % 2)
        {
            if(small.size() > big.size()) return small.top();
            else return big.top();
        }
        else return (small.top() + big.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */