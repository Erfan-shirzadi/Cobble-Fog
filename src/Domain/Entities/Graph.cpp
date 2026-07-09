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

    Nodes[1]=Node{1,NodeType::SIMPLE,{Area::PURPLE}};
    Nodes[2]=Node{2,NodeType::SIMPLE,{Area::PURPLE}};
    Nodes[3]=Node{3,NodeType::SIMPLE,{Area::PURPLE}};
    Nodes[4]=Node{4,NodeType::SIMPLE,{Area::PURPLE,Area::GREEN}};
    Nodes[5]=Node{5,NodeType::SIMPLE,{Area::PURPLE,Area::GREY}};
    Nodes[6]=Node{6,NodeType::SIMPLE,{Area::GREEN,Area::BROWN,Area::CREAM}};
    Nodes[7]=Node{7,NodeType::SECREST,{Area::GREEN}};
    Nodes[8]=Node{8,NodeType::SIMPLE,{Area::GREEN}};
    Nodes[9]=Node{9,NodeType::SIMPLE,{Area::GREEN,Area::GREY}};
    Nodes[10]=Node{10,NodeType::SIMPLE,{Area::GREEN,Area::DARK_BLUE}};
    Nodes[11]=Node{11,NodeType::SIMPLE,{Area::DARK_BLUE,Area::GREY}};
    Nodes[12]=Node{12,NodeType::SIMPLE,{Area::DARK_BLUE}};
    Nodes[13]=Node{13,NodeType::SIMPLE,{Area::DARK_BLUE}};
    Nodes[14]=Node{14,NodeType::SIMPLE,{Area::DARK_BLUE,Area::LIGHT_BLUE}};
    Nodes[15]=Node{15,NodeType::SECREST,{Area::GREY}};
    Nodes[16]=Node{16,NodeType::SIMPLE,{Area::GREY}};
    Nodes[17]=Node{17,NodeType::SIMPLE,{Area::GREY}};
    Nodes[18]=Node{18,NodeType::SIMPLE,{Area::GREY}};
    Nodes[19]=Node{19,NodeType::SIMPLE,{Area::GREY}};
    Nodes[20]=Node{20,NodeType::SIMPLE,{Area::GREY}};
    Nodes[21]=Node{21,NodeType::SIMPLE,{Area::GREY}};
    Nodes[22]=Node{22,NodeType::SIMPLE,{Area::LIGHT_BLUE}};
    Nodes[23]=Node{23,NodeType::SIMPLE,{Area::LIGHT_BLUE}};
    Nodes[24]=Node{24,NodeType::SECREST,{Area::LIGHT_BLUE}};
    Nodes[25]=Node{25,NodeType::SIMPLE,{Area::LIGHT_BLUE}};
    Nodes[26]=Node{26,NodeType::SIMPLE,{Area::LIGHT_BLUE,Area::BROWN}};
    Nodes[27]=Node{27,NodeType::SIMPLE,{Area::BROWN}};
    Nodes[28]=Node{28,NodeType::SIMPLE,{Area::BROWN}};
    Nodes[29]=Node{29,NodeType::SIMPLE,{Area::BROWN}};
    Nodes[30]=Node{30,NodeType::SIMPLE,{Area::CREAM}};
    Nodes[31]=Node{31,NodeType::SIMPLE,{Area::CREAM}};
    Nodes[32]=Node{32,NodeType::SECREST,{Area::CREAM}};

}


Node Graph::GetNode(int node)const{
    return Nodes.at(node);
}

std::vector<int> Graph::GetNeighbors(int node)const{
    return this->graph.at(node);
}

std::vector<Area> Graph::GetArea(int node)const{
    return Nodes.at(node).areas;
}

NodeType Graph::GetNodeType(int node)const{
    return Nodes.at(node).nodetype;
}   
