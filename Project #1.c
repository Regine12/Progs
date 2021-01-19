//C program for computing polynomial project #1,ADS
 #include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#1
typedef struct Poly_Node{
   int coef;
   int exp;
   struct Poly_Node * next;

}Poly_Node;

//#2
void create_Poly(Poly_Node ** p, int coef , int exp){
  Poly_Node * temp = malloc(sizeof(Poly_Node));
  temp->coef=coef;
  temp->exp=exp;
  temp->next=*p;
  *p=temp;

}
//#3
 void display_Poly(Poly_Node *P){
    Poly_Node *p = P;
    p=arrangePoly(p);
    while(p->next->next!=NULL){

        printf(" + %dX^%d  ", p->coef, p->exp);
        p=p->next;
    }

   return ;
}

//#4
int degree_poly(Poly_Node *P){
    Poly_Node *p=P;
    int max=0;
    while(p!=NULL){
      if(max<p->exp){
        max=p->exp;
      }

      p=p->next;
    }
    return max;
}


 Poly_Node * arrangePoly(Poly_Node *p){
    Poly_Node *temp, *ptemp=p;
    int i,deg = degree_poly(p), sum=0;

    for( i=0; i<=deg;i++){
       while(p!=NULL){
         if(i==p->exp){
            sum+=p->coef;
        }
        p=p->next;

       }
       create_Poly(&temp, sum, i);
       sum=0;
       p=ptemp;

    }

  return temp;
  }




//#6
  int eval_poly(Poly_Node *p, int x){
      int result=0;
    while(p!=NULL){
        result+=(p->coef)*(pow(x,p->exp));
        p=p->next;
    }
    printf("\n\t\t p(%d) ==  %d",x,result);
    return result;
  }


void multiCreate(Poly_Node **p){
    printf("Enter num of terms of your polynomial  ");
    int deg,d,i,coef,exp;
    scanf("%d",&deg);
    for(i=deg; i>0;i--){
        printf("coef of term %d  : ",i);
        scanf("%d",&coef);
         printf("exponent of term %d  : ",i);
        scanf("%d",&exp);

        create_Poly(p,coef,exp);
    }
   // *p=arrangePoly(*p);
}

//#7
Poly_Node** multiply_Poly(Poly_Node **R ,Poly_Node *P, Poly_Node *Q){
      Poly_Node *tempP1=P,* tempP2=Q;
      while(tempP1!=NULL){
            tempP2=Q;
        while(tempP2!=NULL){
            create_Poly(R, tempP1->coef * tempP2->coef, tempP1->exp + tempP2->exp);
            tempP2=tempP2->next;
        }
      tempP1=tempP1->next;

      }

        display_Poly(*R);
      return R;
  }

//#5
Poly_Node** add_poly(Poly_Node **R,Poly_Node *P, Poly_Node *Q){
      int deg1= degree_poly(P), deg2=degree_poly(Q);

      P=arrangePoly(P);
      Q=arrangePoly(Q);


      if(deg2>deg1){
        int t=deg2;
        deg2=deg1;
        deg1=deg2;
        Poly_Node *temp;
        temp=P;
        P=Q;
        Q=temp;
      }
      int diff = deg1-deg2,i;
      for(i=deg1; i>=0; i--){
        if(diff>0){
            create_Poly(R,P->coef,i);
            diff--;
        }
        else{
            create_Poly(R, P->coef + Q->coef,i);
            Q=Q->next;
        }
        P=P->next;
      }
      display_Poly(*R);
      return R;
  }


int main(){
  Poly_Node *P=NULL, *Q=NULL, **pp1=&P,**pp2=&Q;
   Poly_Node *p3=NULL, ** R=&p3;
  multiCreate(pp1);
  multiCreate(pp2);
  add_poly(R,P,Q);
//  display_Poly(P);
}

