/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.


Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2


Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/



class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue <int, vector<int>, greater<int>> right;
    priority_queue <int> left;
    deque<int> deq;

    MedianFinder() {
        deq.clear();
    }

    void addNum(int num) {
        cout<<"\n\nAdd Number : "<<num<<endl;
        if(deq.size() == 0)
            deq.push_back(num);
        else if(deq.size() == 1)
        {
            cout<<"Size 1 : ";
            if(num < deq.front())
            {
                left.push(num);
                deq.push_front(left.top());
                cout<<"Push left and top: "<< left.top() <<endl;
                left.pop();
            }
            else
            {

                right.push(num);
                deq.push_back(right.top());
                cout<<"Push right and top: "<< right.top() <<endl;
                right.pop();
            }
        }
        else if(deq.size() == 2)
        {
            cout<<"Size 2 : ";
            if(num<=deq.front()){
                left.push(num);
                right.push(deq.back());
                deq.pop_back();
            }
            else if(num>=deq.back())
            {
                left.push(deq.front());
                right.push(num);
                deq.pop_front();
            }
            // This would be the median item
            else
            {
                left.push(deq.front());
                right.push(deq.back());
                deq.pop_front();
                deq.pop_back();
                deq.push_back(num);
            }
        }
    }

    double findMedian() {
        double med = 0.0;

        if(deq.size() == 1)
            return deq.back();
        else if(deq.size() == 2)
        {
            return (  (double)(deq.front()+deq.back()) / 2.0 );
        }
        else
            return NULL;

        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
