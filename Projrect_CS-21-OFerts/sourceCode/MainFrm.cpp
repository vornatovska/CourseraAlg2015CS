#include <vcl.h>
#pragma hdrstop
#include "MainFrm.h"
#include "Properities.h"
#include "Geneal_tree_class.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
struct gen_tree
  {
    AnsiString Identificator;
    AnsiString PIB;
    bool is_spouse;
    AnsiString spouse_PIB;
    TDateTime birthday;
    bool is_dead;
    TDateTime date_of_death;
    unsigned int numb_of_children;
    gen_tree *child[5];
  } cur,rt;
int st_x=450,st_y=10;
unsigned int nmb=0;
int level=0,dist=0,x_par,y_par;
bool was_level=false;
AnsiString pred_ident;
Tfrm_Main_Form *frm_Main_Form;
GenealTree *current,*root=NULL;
__fastcall Tfrm_Main_Form::Tfrm_Main_Form(TComponent* Owner)
        : TForm(Owner)
{
}
void __fastcall Tfrm_Main_Form::draw_tree()
  {
    for (unsigned int i=0;i<numb;i++)
      {
      if (!was_level)
       dist=0;
       current=root->find_ident_node(frm_properities->cb_ident->Items->Strings[i]);
       im_Genealogic_Tree_View->Canvas->Font->Color=clRed;
       im_Genealogic_Tree_View->Canvas->TextOut(st_x+dist,st_y+level,"["
+current->Identificator+"] "
+current->PIB);
       if (current->is_dead)
         im_Genealogic_Tree_View->Canvas->TextOut(st_x+dist,st_y+level+20,DateToStr(current->birthday)+"-
"+DateToStr(current->date_of_death));
       else
         im_Genealogic_Tree_View->Canvas->TextOut(st_x+dist,st_y+20+level,"???. "+DateToStr(current-
>birthday));
       im_Genealogic_Tree_View->Canvas->Font->Color=clBlue;
       if (current->is_spouse)
         im_Genealogic_Tree_View->Canvas->TextOut(st_x+170+dist,st_y+level,current->spouse_PIB); 
       if (numb>=i&&root->find_ident_node(frm_properities->cb_ident->Items->Strings[i+1])-
>Identificator[1]!=current->Identificator[1])
        {
         was_level=false;
         x_par=st_x+dist;
         y_par=st_y+level+40;
         im_Genealogic_Tree_View->Canvas->MoveTo(x_par,y_par);
         im_Genealogic_Tree_View->Canvas->LineTo(x_par-dist,st_y+level+80);
         dist=0;
        }
       else
         {
           was_level=true;
           im_Genealogic_Tree_View->Canvas->MoveTo(x_par,y_par);
           im_Genealogic_Tree_View->Canvas->LineTo(x_par+dist,st_y+80);
         }
       if (!was_level)
         level+=80;
       else
         {
         if (numb>=i&&current->is_spouse)
         dist+=345;
         else
         dist+=175;
         }
       pred_ident=current->Identificator;
    }
  }
void __fastcall Tfrm_Main_Form::bt_Add_ElemClick(TObject *Sender)
{
  if (root!=NULL)
    {
     frm_properities->cb_ident->Items->Clear();
   frm_properities->cb_ident->Items->Add("1_1");
     root->load_idents_to_cb();
     frm_properities->clear_form(false);
    }
  else
    frm_properities->clear_form(true);
    If (frm_properities->ShowModal()== 0x1)
     {
         if (root==NULL)
          {
            root=new GenealTree;
            current=root;
          }
         else
          {
           current=root->find_ident_node(frm_properities->cb_ident->Text);
             if (current->numb_of_children<5)
                current->child[current->numb_of_children++]=new GenealTree(root);
          }
       current=root;
       level=0;
       dist=0;
       ScrollBox1->HorzScrollBar->Position=400;
       nmb=0;
       im_Genealogic_Tree_View->Canvas->Rectangle(5,5,im_Genealogic_Tree_View->ClientWidth-5,im_Genealogic_Tree_View->ClientHeight-5);
       frm_properities->cb_ident->Items->Clear();
       frm_properities->cb_ident->Items->Add("1_1");
       root->load_idents_to_cb();
       draw_tree();
      }
}
void __fastcall Tfrm_Main_Form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (root) delete(root);
}
void __fastcall Tfrm_Main_Form::load_info(bool is_shown=false)
  {
  GenealTree *tmp;
    if (!is_shown)
  {
   if (!root)
    ShowMessage("В базі не знайдено жодного вузла дерева для редагування! Спочатку додайте вузли за допомогою кнопки "Додати особу"...");
   else
    {
      frm_properities->cb_ident->Items->Clear();
      frm_properities->cb_ident->Items->Add("1_1");
      root->load_idents_to_cb();
      root->load_data_to_form();
      if (frm_properities->ShowModal()==0x1&&frm_properities->ed_pib->Text!="")
        {
          tmp=root->find_ident_node(frm_properities->cb_ident->Text);
          tmp->PIB=frm_properities->ed_pib->Text;
          if (frm_properities->cb_have_spouse->Checked&&frm_properities->ed_spouse->Text!="")
            {
              tmp->is_spouse=true;
              tmp->spouse_PIB=frm_properities->ed_spouse->Text;
            }
          else
            {
              tmp->is_spouse=false;
              tmp->spouse_PIB="";
            }
          tmp->birthday=frm_properities->dtp_date_of_birth->Date;
          if (frm_properities->cb_is_dead->Checked)
            tmp->date_of_death=frm_properities->dtp_date_of_death->Date;
        current=root;
       level=0;
       dist=0;
       ScrollBox1->HorzScrollBar->Position=400;
       nmb=0;
       im_Genealogic_Tree_View->Canvas->Rectangle(5,5,im_Genealogic_Tree_View->ClientWidth-5,im_Genealogic_Tree_View->ClientHeight-5);
       frm_properities->cb_ident->Items->Clear();
       frm_properities->cb_ident->Items->Add("1_1");
       root->load_idents_to_cb();
       draw_tree();
        }
    }
  }
else
  {
    (root->find_ident_node(frm_properities->cb_ident->Text))->load_data_to_form();
  }
  }
void __fastcall Tfrm_Main_Form::bt_Edit_ElemClick(TObject *Sender)
{
  if (Sender==frm_properities->cb_ident)
    load_info(true);
  else
    load_info();
}

void __fastcall Tfrm_Main_Form::bt_Save_TreeClick(TObject *Sender)
{
  if (sd_Save_Tree->Execute());
}
void __fastcall Tfrm_Main_Form::bt_Load_TreeClick(TObject *Sender)
{
  if (od_Load_Tree->Execute());
}

