#include<bits/stdc++.h>
int min_signaltower_cost,edge_count,num_signaltower,earlist_ancest[1010],match_count,temp_variable1,temp_variable2;
inline int quick_read(){
    int result=0,result_sign=1;
    char temp_digit=getchar();
    while(temp_digit<'0'||temp_digit>'9')
	{
        if(temp_digit=='-')
            result_sign=-1;
        temp_digit=getchar();
    }
    while(temp_digit>='0'&&temp_digit<='9')
	{
        result=(result<<1)+(result<<3)+(temp_digit^48);
        temp_digit=getchar();
    }
    return result*result_sign;
}
struct type_signaltower{
	int x_coordinate,y_coordinate;
}signaltower[1010];
struct type_edge{
	int start_point,destination,edge_value;
}edge[2000010];
inline void add_edge(int new_edge_from,int new_edge_destination,int new_edge_value){
	edge[++edge_count]=(type_edge){new_edge_from,new_edge_destination,new_edge_value};
}
inline int calculate_distance(type_signaltower signaltower1,type_signaltower signaltower2){
	return (signaltower1.x_coordinate-signaltower2.x_coordinate)*(signaltower1.x_coordinate-signaltower2.x_coordinate)+(signaltower1.y_coordinate-signaltower2.y_coordinate)*(signaltower1.y_coordinate-signaltower2.y_coordinate);
}
bool edge_compare_lesser(type_edge edge1,type_edge edge2){
	return edge1.edge_value<edge2.edge_value;
}
inline int find_ancest(int target){
	if(earlist_ancest[target]==target)
		return target;
	return earlist_ancest[target]=find_ancest(earlist_ancest[target]);
}
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	std::ios::sync_with_stdio(false);
	num_signaltower=quick_read();
	for(int temp_signaltower=1;temp_signaltower<=num_signaltower;++temp_signaltower){
		earlist_ancest[temp_signaltower]=temp_signaltower;
	}
	for(int temp_signaltower=1;temp_signaltower<=num_signaltower;++temp_signaltower){
		signaltower[temp_signaltower]=(type_signaltower){quick_read(),quick_read()};
	}
	for(int temp_from=1;temp_from<=num_signaltower;++temp_from){
		for(int temp_destination=temp_from+1;temp_destination<=num_signaltower;++temp_destination){
			add_edge(temp_from,temp_destination,calculate_distance(signaltower[temp_from],signaltower[temp_destination]));
		}
	}
	std::sort(edge+1,edge+edge_count+1,edge_compare_lesser);
	int temp_edge_from_ancest,temp_edge_destination_ancest;
	for(int temp_edge=1;match_count<num_signaltower-1;++temp_edge){
		temp_edge_from_ancest=find_ancest(edge[temp_edge].start_point);
		temp_edge_destination_ancest=find_ancest(edge[temp_edge].destination);
		if(temp_edge_destination_ancest!=temp_edge_from_ancest){
			earlist_ancest[temp_edge_from_ancest]=earlist_ancest[temp_edge_destination_ancest];
			min_signaltower_cost=edge[temp_edge].edge_value;
			match_count++;
		}
	}
	std::cout<<min_signaltower_cost;
	return 0;
}
/*啊哈沃德最近喜欢阅读古代故事，他了解到古代战争是通过烽火台传递信息的，他也想
模拟一下这个过程。
假设有 n 个烽火台，每座烽火台都有一定的经费，获得经费多的可以采购更多的燃料
升起更大的烟，这样他们的信息就可以传递的更远，经费为 p 的烽火台可以传递信息的距
离就是 ，烽火台的信息可以通过其他烽火台做中介，传到距离超过 的烽火台的位置。
啊哈沃德决定给每座烽火台经费都为 x，请你帮忙确定一下 x 的最小值，使得任一烽火
台发出的信息都能到达其他所有烽火台。
输入格式 tower.in：
输入的第一行一个整数 n，表示有 n 个烽火台。
接下来 n 行每行两个整数 x, y，分别表示该烽火台的坐标(x, y)。
输出格式 tower.out：
输出一个整数，表示 x 的最小值。
样例输入：
4
1 3
5 4
7 2
6 1
样例输出：
17
数据范围：
1<=n<=1000
1<=x, y<=25000*/
