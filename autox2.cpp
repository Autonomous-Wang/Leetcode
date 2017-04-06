#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdbool>
using namespace std;

vector < vector < float > > convolute(vector < vector < int > > input, vector < vector < float > > &kernel)
{
  int krow = kernel.size();
  int kcol = kernel[0].size();
  int mrow = input.size();
  int mcol = input[0].size();
  int k_cenx = kcol / 2;
  int k_ceny = krow / 2;
  
  vector<float> v(mcol, 0); 
  vector<vector<float> > result(mrow,v);
  vector<float> v1(kcol, 0); 
  vector<vector<float> > re(krow,v1);
  
  for (int i = 0; i < mrow; ++i){
    for (int j = 0; j < mcol; ++j){
      for (int m = 0; m < krow; ++m){
        
        // flip the row of kernel
        int mm = krow - 1 - m; 
        for (int n = 0; n < kcol; ++n){

          // flip the col of kernel
          int nn = kcol - 1 - n;
          // get the surrounding elements around the center of kernel
          int ii = i + (m - k_ceny);
          int jj = j + (n - k_cenx);
          if (ii>=0 && ii < mrow && jj >= 0 && jj < mcol)
          {
            result[i][j] += input[ii][jj] * kernel[mm][nn];
          }
        }
      }
    }
  }
  
  // remove the edge so that the result is a 3 by 3 vector as required
  cout << "The result for part 1:" << endl;
  cout << endl;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      re[i][j] = result[i+1][j+1];
      cout << re[i][j] <<' ';
    }
    cout << endl;
  }
  return re;
}

// check unique elements
bool check(vector<int> vec, int x)
{
  int l = vec.size();
  for (int i = 0; i < l; i++)
  {
    if (x == vec[i])
    {
      return false;
    }
  }
  return true;
}

vector < vector < float > >  setRandomZero(vector < vector < float > > result, int k)
{
  vector<int> vec;
  while ( int(vec.size()) <= k)
  {
    int num = rand() % 9;
    if (check(vec, num))
    {
      vec.push_back(num);
    }
  }

  // the vac contains the index for the zero element
  vector<int> v2(2); 
  vector<vector<int> > ss(k,v2);
  for (int m = 0; m < k; m++)
  {  
      ss[m][0] = vec[m]/3;
      ss[m][1] = vec[m]%3;
  }

  // set random k elements to zero
  for (int m = 0; m < k; m++)
  {  
      result[ss[m][0]][ss[m][1]] = 0; 
  }

  // print the results 
  cout << endl;
  cout << "The result for part 2:" << endl;
  cout << endl;
  for (int m = 0; m < 3; m++)
  {  
      for (int n = 0; n < 3; n++)
      {
          cout << result[m][n] << ' ';
      }
    cout << endl;
  }
  return result;
}

// rotate by 90 degrees
vector<vector<float> >rotate(vector<vector<float> > result, int theta)
{
  // creat a vector to store the data
  vector<float> v2(result[0].size()); 
  vector<vector<float> > temp(result.size(),v2);
  int count1 = 0;
  int count2 = 0;
  int l = result.size();
  for (count1 = 0; count1 < l; count1++)
  {
    for (count2 = 0; count2 < l; count2++)
    {
        temp[temp.size()-count1-1][count2] = result[count2][count1];
    }
  }

  cout << "The result for part 3:"<< endl;
  cout << endl;
  for (count = 0; count < l; count++)
  {
    for (count2 = 0; count2 < l; count2++)
    {  
        cout << temp[count][count2] <<' ';
    }
    cout << endl;
  }
  return temp;
}


#define ROW 3
#define COL 3
int isValid(vector<vector<float> > result, int row, int col, bool visited[][COL])
{
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL) &&
           (result[row][col] && !visited[row][col]);
}

void DFS (vector<vector<float> > result, int row, int col, bool visited[][COL])
{
  int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // 8 neighbors
  int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  visited[row][col] = true;
  for (int k = 0; k < 8; k++)
  {
    if (isValid(result, row + rowNbr[k], col + colNbr[k], visited))
    {
      DFS(result, row + rowNbr[k], col + colNbr[k], visited);
    }
  }
}

// function for connected component count
int connectedComponent(vector<vector<float> >result)
{  
    int l = result.size();
    bool visited[3][3];
    memset(visited, 0, sizeof(visited));
    
    int count = 0;
    for (int i = 0; i < l; i++){
      for (int j = 0; j < l; j++){
        if (result[i][j] && !visited[i][j])
        {
          DFS(result, i, j, visited);
          ++ count;
        }
      }
    }
    return count;
}

int main()
{
    vector<int> v2(5, 1); 
    vector<vector<int> > input(5,v2);
    input[0][2] = 5;
  
    vector<float> v(3, 0); 
    vector<vector<float> > kernel(3,v);
    kernel[0][1] = 1;
    kernel[2][1] = 1;

    vector<vector<float> > result_step1 = convolute(input, kernel);
    // second question
    const int k =7;
    const float theta = 90;

    vector < vector<float > >  result_step2 = setRandomZero(result_step1, k);
    cout << endl;
    
    vector<vector<float> > result_step3 = rotate(result_step2, theta);
    
    int connected_areas = connectedComponent(result_step3);
    cout << endl;
    cout << "The result for part 4" << endl;
    cout << endl;
    cout << connected_areas << endl;
}

 