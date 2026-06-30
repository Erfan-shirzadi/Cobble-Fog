#include "Domain/Entities/Graph.h"

Graph::Graph(){

    SetNodes();
    graph[1]={2,4};
    graph[2]={1,3,5};
    graph[3]={1,2,4,31};
    graph[4]={1,3,6,7,19,20};
    graph[5]={2,20,21};
    graph[6]={28,29,30,31};
    graph[7]={4,8,15,24,32};
    graph[8]={7,9,10};
    graph[9]={8,17,18,19};
    graph[10]={8,11};
    graph[11]={10,12,15};
    graph[12]={11,13,23};
    graph[13]={12,14};
    graph[14]={13,22,26};
    graph[15]={7,11,16,24,32};
    graph[16]={15,17};
    graph[17]={9,16,18};
    graph[18]={9,17,19};
    graph[19]={4,9,18,20};
    graph[20]={4,5,19,21};
    graph[21]={5,20};
    graph[22]={14,23};
    graph[23]={12,22,24};
    graph[24]={7,15,23,25,32};
    graph[25]={24,26};
    graph[26]={14,25,27};
    graph[27]={26,28,29};
    graph[28]={6,27,29};
    graph[29]={6,27,28};
    graph[30]={6,31,32};
    graph[31]={6,30};
    graph[32]={7,15,24,30};

}

void Graph::SetNodes(){

    Nodes[1]=Node{1,{Area::PURPLE}};
    Nodes[2]=Node{2,{Area::PURPLE}};
    Nodes[3]=Node{3,{Area::PURPLE}};
    Nodes[4]=Node{4,{Area::PURPLE,Area::GREEN}};
    Nodes[5]=Node{5,{Area::PURPLE,Area::GREY}};
    Nodes[6]=Node{6,{Area::GREEN,Area::BROWN,Area::CREAM}};
    Nodes[7]=Node{7,{Area::GREEN}};
    Nodes[8]=Node{8,{Area::GREEN}};
    Nodes[9]=Node{9,{Area::GREEN,Area::GREY}};
    Nodes[10]=Node{10,{Area::GREEN,Area::DARK_BLUE}};
    Nodes[11]=Node{11,{Area::DARK_BLUE,Area::GREY}};
    Nodes[12]=Node{12,{Area::DARK_BLUE}};
    Nodes[13]=Node{13,{Area::DARK_BLUE}};
    Nodes[14]=Node{14,{Area::DARK_BLUE,Area::LIGHT_BLUE}};
    Nodes[15]=Node{15,{Area::GREY}};
    Nodes[16]=Node{16,{Area::GREY}};
    Nodes[17]=Node{17,{Area::GREY}};
    Nodes[18]=Node{18,{Area::GREY}};
    Nodes[19]=Node{19,{Area::GREY}};
    Nodes[20]=Node{20,{Area::GREY}};
    Nodes[21]=Node{21,{Area::GREY}};
    Nodes[22]=Node{22,{Area::LIGHT_BLUE}};
    Nodes[23]=Node{23,{Area::LIGHT_BLUE}};
    Nodes[24]=Node{24,{Area::LIGHT_BLUE}};
    Nodes[25]=Node{25,{Area::LIGHT_BLUE}};
    Nodes[26]=Node{26,{Area::LIGHT_BLUE,Area::BROWN}};
    Nodes[27]=Node{27,{Area::BROWN}};
    Nodes[28]=Node{28,{Area::BROWN}};
    Nodes[29]=Node{29,{Area::BROWN}};
    Nodes[30]=Node{30,{Area::CREAM}};
    Nodes[31]=Node{31,{Area::CREAM}};
    Nodes[32]=Node{32,{Area::CREAM}};

}


Node Graph::GetNode(int node)const{
    return Nodes.at(node);
}

std::vector<int> Graph::GetNeighbors(int node)const{
    return this->graph.at(node);
}
