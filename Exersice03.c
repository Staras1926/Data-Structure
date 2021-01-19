#include<stdio.h>
#include<stdlib.h>
#include <string.h>
///domi tou dentrou
typedef struct node{
    int *barcode;
    double timi;
    char *katigoria;
    char *im_paralavis;
    char *im_apothikeusis;
    char *im_liksis;
    struct node *right;
    struct node *left;
}node;

node *head;


///kataxwrisi stoixeiwn proiontos me vasi tn kwdiko-barcode
node *addNode(node *head,int *barcode){

    ///DHMIOURGIA KOMVOU
    if(head==NULL){
        node *current;
        current=(node*)malloc(sizeof(node));
        current->barcode=barcode;
        current->left=NULL;
        current->right=NULL;
    }

    ///FTIAXNEI KOMVO STO ARISTERO PAIDI
    else if(barcode<head->barcode){
        head->left = addNode(head->left,barcode);
    }

    ///FTIAXNEI KOMVO STO DEKSI PAIDI
    else if(barcode>head->barcode){
        head->right=addNode(head->right,barcode);
    }

    return head;
}

///anazitisi stoixeiwn me vasi ton kwdiko-barcode
node* Search(node *head,int *barcode){

    //AN H LISTA EINAI ADEIA H
    //OTAN VREI THN LEKSH EPISTREFEI TON KOMVO
    if ((head==NULL) || (head->barcode=barcode)){
        return head;
    }

    //PSAXNEI STO DEKSI PAIDI
    else if(head->barcode<barcode){
        return Search(head->right,barcode);
    }

    //PSAXNEI STO ARISTERO
    else if(head->barcode>barcode){
        return Search(head->left,barcode);
    }
}


void display(node *head) {
    //DIASXISH KAI EMFANISH DENTROU
    if (head != NULL) {
        display(head->left);
        printf("%s", head->barcode);
        display(head->right);
    }
}

///diagrafi komvou me vasi to barcode
node * deletenode(struct node *node, int barc)
{
    if(node==NULL)
        return NULL;
    else if(barc < node->barcode) ///an to am mikrotero tou am tou tree psakse  aristera
        node->left = deletenode(node->left, barc);
    else if(barc > node->barcode) ///an to barcode megalytero tou barcode tou tree psakse  deksia
        node->right = deletenode(node->right, barc);
    else///gia na ta sbhsw
    {
        ///an dn exei paidi
        if(node->left == NULL && node->right == NULL)
        {
            node = NULL;
        }
        else if(node->left == NULL)///an exei mono deksi paidi
        {
            node = node->right;
        }
        else if(node->right == NULL) ///an exei mono aristero paidi
        {
            node = node->left;
        }
        else ///an exei dio paidia
        {
            struct node *temp = findMinimum(node->right);///briskw to pio katw node
            node->barcode = temp->barcode;
            node->right = deletenode(node->right, temp->barcode);
        }
    }

    return node;
}
///voithitiki sunartisi gia mena
int findMinimum(struct node *node)///gia na brw to pio katw node
{
    if(node->left==NULL)
        return node;

    return findMinimum(node->left);
}
///euresi pio akrivou
double findMax_timi(struct node* node)
{
    ///an adeio
    if (node == NULL)
        return -1;

    double result = node->timi;
    double left_result = findMax_timi(node->left);
    double right_result = findMax_timi(node->right);
    if (left_result > result)
        result = left_result;
    if (right_result > result)
        result = right_result;
    return result;
}



int main(){







}
