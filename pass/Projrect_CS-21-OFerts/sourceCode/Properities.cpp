#include <vcl.h>
#pragma hdrstop

#include "Properities.h"
#include "MainFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_properities *frm_properities ;

__fastcall Tfrm_properities::Tfrm_properities(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall Tfrm_properities::clear_form(bool is_first)
  {
   Caption="Введення даних про особу";
   lb_ident->Caption="Виберіть із списку ідентифікатор об'єкта до якого ви хочете додати особу";
   if (is_first)
     {
       cb_ident->Text="";
       cb_ident->Enabled=false;
       cb_ident->Color=clBtnFace;
     }
   else
    {
      cb_ident->Text="1_1";
      cb_ident->Enabled=true;
      cb_ident->Color=clWindow;
    }

    dtp_date_of_birth->Date=Date();
    dtp_date_of_death->Date=Date();

    ed_spouse->Text="";
    ed_pib->Text="";
    cb_have_spouse->Checked=false;
    cb_is_dead->Checked=false;
    dtp_date_of_death->Enabled=false;
    dtp_date_of_death->Color=clBtnFace;
    ed_spouse->Enabled=false;
    ed_spouse->Color=clBtnFace;
  }
void __fastcall Tfrm_properities::cb_is_deadClick(TObject *Sender)
{
  if (cb_is_dead->Checked)
    {
      dtp_date_of_death->Enabled=true;
      dtp_date_of_death->Color=clWindow;
    }
  else
    {

      dtp_date_of_death->Enabled=false;
      dtp_date_of_death->Color=clBtnFace;
    }
}

void __fastcall Tfrm_properities::cb_have_spouseClick(TObject *Sender)
{
 if (cb_have_spouse->Checked)
    {
      ed_spouse->Enabled=true;
      ed_spouse->Color=clWindow;
    }
  else
    {
      ed_spouse->Enabled=false;
      ed_spouse->Color=clBtnFace;
    }
}

void __fastcall Tfrm_properities::cb_identChange(TObject *Sender)
{
if (Caption[1]=='?')
frm_Main_Form->bt_Edit_ElemClick(cb_ident);
}

