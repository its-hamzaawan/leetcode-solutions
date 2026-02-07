class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int m = sandwiches.size();
        int front = 0;
        int rear = n-1;
        int rotation = 0;
        int top=0;
   while(front <= rear){
    if(students[front] == sandwiches[top]){
        front++;
        top++;
        rotation=0;
       
    }
    else{
        students.push_back(students[front]);
        front++;
        rear++;
        rotation++;
    }
    if(rotation > rear - front + 1){
        break;
    }
   }
   return rear - front +1;
    }
};