#include "Properities.h"

 class GenealTree
  {
   public:
    AnsiString Identificator;
    AnsiString PIB;
    bool is_spouse;
    AnsiString spouse_PIB;
    TDateTime birthday;
    bool is_dead;
    TDateTime date_of_death;
    unsigned int numb_of_children;
    GenealTree *child[5];
      GenealTree(GenealTree* rt);
     ~GenealTree();
    void load_idents_to_cb();
    GenealTree* find_ident_node(AnsiString f_ident);
    void load_data_to_form();
  };

unsigned int numb=0;
GenealTree *tmp;
void GenealTree::load_data_to_form()
  {
     frm_properities->Caption="Редагування даних";
     frm_properities->lb_ident->Caption="Виберіть із списку ідентифікатор об'єкта для редагування відповідної особи:";
     frm_properities->cb_ident->Text=Identificator;
     frm_properities->cb_ident->Enabled=true;
     frm_properities->cb_ident->Color=clWindow;
     frm_properities->ed_pib->Text=PIB;
     frm_properities->dtp_date_of_birth->Date=birthday;
     if (is_dead)
       {
        frm_properities->cb_is_dead->Checked=true;
        frm_properities->dtp_date_of_death->Date=date_of_death;
        frm_properities->dtp_date_of_death->Enabled=true;
        frm_properities->dtp_date_of_death->Color=clWindow;
       }
     else
       {
        frm_properities->cb_is_dead->Checked=false;
        frm_properities->dtp_date_of_death->Date=Date();
        frm_properities->dtp_date_of_death->Enabled=false;
        frm_properities->dtp_date_of_death->Color=clBtnFace;
       }
     if (is_spouse)
       {
         frm_properities->ed_spouse->Text=spouse_PIB;
         frm_properities->cb_have_spouse->Checked=true;
         frm_properities->ed_spouse->Enabled=true;
         frm_properities->ed_spouse->Color=clWindow;
        }
     else
       {
         frm_properities->ed_spouse->Text="";
         frm_properities->cb_have_spouse->Checked=false;
         frm_properities->ed_spouse->Enabled=false;
         frm_properities->ed_spouse->Color=clBtnFace;

       }
  }
GenealTree* GenealTree::find_ident_node(AnsiString f_ident)
  {
    if (Identificator==f_ident) tmp=this;
    else
      for (unsigned int i=0;i<numb_of_children;i++)
          if (child[i]->Identificator==f_ident)
            tmp=child[i];
          else
            child[i]->find_ident_node(f_ident);
    return tmp;
  }

void GenealTree::load_idents_to_cb()
  {
    for (unsigned int i=0;i<numb_of_children;i++)
    if (child[i]!=NULL)
      {
        frm_properities->cb_ident->Items->Add(child[i]->Identificator);
        child[i]->load_idents_to_cb();
      }
  }


GenealTree::GenealTree(GenealTree* rt=NULL)
 {
int tmp=0,n_ch;
   if (rt==NULL)
     Identificator="1_1";
   else
     {
  tmp=StrToInt(frm_properities->cb_ident->Text.SubString(3,frm_properities->cb_ident->Text.Length()-3+1));
       if (numb==1) n_ch=0;
       else
       n_ch=rt->find_ident_node(frm_properities->cb_ident->Text)->numb_of_children;
       Identificator=IntToStr(StrToInt(frm_properities->cb_ident->Text[1])+1)
       +"_"+IntToStr(tmp*5-(5-n_ch)+1);
     }

   PIB=frm_properities->ed_pib->Text;

   if (frm_properities->cb_have_spouse->Checked&&frm_properities->ed_spouse->Text!="")
     {
      is_spouse=true;
      spouse_PIB=frm_properities->ed_spouse->Text;
     }
   else
     {
     is_spouse=false;
     spouse_PIB="";
     }
   birthday=frm_properities->dtp_date_of_birth->Date;

   if (frm_properities->cb_is_dead->Checked)
     {
      is_dead=true;
      date_of_death=frm_properities->dtp_date_of_death->Date;
     }
   else
     {
      is_dead=false;
      date_of_death=0;
     }


   numb_of_children=0;
   for (int i=0;i<5;i++)
     child[i]=NULL;
   numb++;

 }
GenealTree::~GenealTree()
  {
    for (int i=0;i<5;i++)
      if (child[i]) delete child[i];
  }

