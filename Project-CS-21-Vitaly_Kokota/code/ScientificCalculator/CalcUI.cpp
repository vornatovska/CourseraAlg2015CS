#include "CalcUI.h"

using namespace ScientificCalculator;

// Î÷èùåííÿ ôîğìè
void CalcUI::ClearOutput()
{
	_lastResult = 0;
	ShowValue();
	_lastAction = CulculationActions::None;
}

// Äğóê ğåçóëüòàòó íà ôîğìó
void CalcUI::ShowValue()
{
	Output = _lastResult.ToString();
}

// Ïåğåâ³ğêà ÷è ââåäåíî êîğèñòóâà÷åì ùîñü íà ôîğì³
bool CalcUI::NotEmptyOutput()
{
	return Output->Length > 0 && !String::IsNullOrEmpty(Output);
}
// Ä³ñòàº çíà÷åííÿ ç ôîğìè ³ çàïèñóº â çì³ííó êëàñó
void CalcUI::ExctractValueFromForm()
{
	_lastResult = Double::Parse(Output->Replace(L",", L"."));

}
// Çàïàì'ÿòîâóº îñòàííº ââåäåíå çíà÷åííÿ êîğèñòóâà÷åì
double CalcUI::StoreResult()
{
	ExctractValueFromForm();
	Output = DEFAULT_VAL;
	return _lastResult;
}

// Ïğîâîäèòü êàëüêóëÿö³ş ğåçóëüòàòó
void CalcUI::Calculate()
{
	double
		first = _lastResult,
		sec = StoreResult();
	switch (_lastAction)
	{
	case CulculationActions::Add:
		_lastResult = scientific_calculator::add(first, sec);
		break;
	case CulculationActions::Sub:
		_lastResult = scientific_calculator::sub(first, sec);
		break;
	case CulculationActions::Mul:
		_lastResult = scientific_calculator::mul(first, sec);
		break;
	case CulculationActions::Div:
		_lastResult = scientific_calculator::div(first, sec);
		break;
	case CulculationActions::Pow:
		_lastResult = scientific_calculator::pow(first, sec);
		break;
	case CulculationActions::Sqrt:
		_lastResult = scientific_calculator::sqrt(first, sec);
		break;
	case CulculationActions::Mod:
		_lastResult = scientific_calculator::mod(first, sec);
		break;
	case CulculationActions::Log:
		_lastResult = scientific_calculator::log(sec);
		break;
	case CulculationActions::Fact:
		_lastResult = scientific_calculator::fact(sec);
		break;
	case CulculationActions::Tan:
		_lastResult = scientific_calculator::tan(sec);
		break;
	case CulculationActions::Sin:
		_lastResult = scientific_calculator::sin(sec);
		break;
	case CulculationActions::Cos:
		_lastResult = scientific_calculator::cos(sec);
		break;
	}
	if (_lastAction != CulculationActions::None)
	{
		_lastAction = CulculationActions::None;
		ShowValue();
	}
}



Void CalcUI::OnBackspaceBtnClick(Object^  sender, EventArgs^  e) {
	if (NotEmptyOutput())
	{
		Output = Output->Substring(0, Output->Length - 1);
		if (Output->Length == 0)
		{
			Output = DEFAULT_VAL;
		}
	}
}
Void CalcUI::OnClearBtnClick(Object^  sender, EventArgs^  e) {
	ClearOutput();
}
Void CalcUI::OnInvertBtnClick(Object^  sender, EventArgs^  e) {
	if (NotEmptyOutput())
	{
		Output = Output[0] == '-' ? Output->Substring(1, Output->Length - 1) : Output->Insert(0, L"-");
	}
}
Void CalcUI::OnResultBtnClick(Object^  sender, EventArgs^  e) {
	Calculate();
}
Void CalcUI::OnTypeNumberClick(Object^  sender, EventArgs^  e) {
	auto val = (String^) ((Button^) sender)->Tag;
	if (val == L"," && Output->IndexOf(L",") != -1) return;
	if ((Output == DEFAULT_VAL && val != L",") || (_lastAction != CulculationActions::None && _lastResult.ToString() == Output))
	{
		Output = EMPTY_STR;
	}
	Output += val;
}
Void CalcUI::OnSingleNumberOperationBtnClick(Object^  sender, EventArgs^  e) {
	_lastAction = (CulculationActions) (int) Convert::ToInt32(((Button^) sender)->Tag);
	Calculate();
}
Void CalcUI::OnOperationBtnClick(Object^  sender, EventArgs^  e) {
	Calculate();
	_lastAction = (CulculationActions) (int) Convert::ToInt32(((Button^) sender)->Tag);
}
