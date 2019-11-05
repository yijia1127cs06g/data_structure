#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

class Queue {
    private:
        vector<char> queue;
        int _front;
        int _rear;
        int _maxSize;
    public:
        bool isEmpty() {
            if (_front == _rear)
                return true;
            else
                return false;
        }
        bool isFull() {
            if ((_rear+1)%_maxSize == _front)
                return true;
            else
                return false;
        }
        void enqueue(char c) {
            if (isFull())
                return;
            else{
               _rear = (_rear+1)%_maxSize;
               queue[_rear] = c;
            }
        }

        void queue_or_cut(vector<char> &group, char c){
            int memIdx = search_first_mem_idx(group);
            if (memIdx == -1){
                enqueue(c);
            }
            else{
                for (int i = _rear; i>=memIdx; i--)
                    queue[i+1] = queue[i];
                queue[memIdx] = c;
                _rear++;
            }
        }

        int search_first_mem_idx(vector<char> &group){
            int minIdx = INT_MAX;
            vector<char>::iterator it;
            for (int i=0; i<group.size(); i++){
                it = find(queue.begin()+_front+1, queue.end(),group[i]);
                if (it != queue.end()){
                    if ((it - queue.begin()) < minIdx)
                        minIdx = it - queue.begin();
                }
            }
            return minIdx!=INT_MAX?minIdx:-1;
        }
        char dequeue() {
            if (!isEmpty()){
                _front = (_front+1)%_maxSize;
                return queue[_front];
            }
        }
        int get_size(){
            if (_front<_rear)
                return _rear - _front;
            else
                return _maxSize - (_front-_rear);
        }
        Queue(int maxSize) {
            _maxSize = maxSize;
            _front = 0;
            _rear = 0;
            queue.resize(maxSize);
        }
};

bool in_group(vector<char> &group, char member){
    for (int i = 0; i<group.size(); i++){
        if (member == group[i])
            return true;
    }
    return false;
}


int main(){
    int N, M;
    int total_member = 0;
    char temp;
    char member;
    vector<vector<char> > group_member;
    string buffer;
   
    cin >> N;
    group_member.resize(N);
    for (int i = 0; i<N; i++){
        cin >> M;
        total_member += M;
        while(M--){
            cin >> member;
            group_member[i].push_back(member);
        } 
    }

    Queue Q = Queue(10*total_member+1);
    while(getline(cin, buffer)){
        if (buffer[0]=='D')
            cout << Q.dequeue() << endl;
        else if (buffer[0] == 'E'){
            bool is_queued = false;
            member = buffer[buffer.length()-1];
            for (int i = 0; i<group_member.size(); i++){
                if (in_group(group_member[i], member)){
                    Q.queue_or_cut(group_member[i], member);
                    is_queued = true;
                    break;
                }
            }
            if (!is_queued)
                Q.enqueue(member);
        }
        else{
            continue;
        }
    }

    return 0;
}
