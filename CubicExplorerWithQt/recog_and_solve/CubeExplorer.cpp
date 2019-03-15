#include"CubeExplorer.h"

CubeExplorer::CubeExplorer(char* cstr,HandState& hs):target(cstr),handState(hs){}

void CubeExplorer::SetTarget(string str) { target = str; }

vector<string>& CubeExplorer::GetVecStrSerial() { return vecStrSerial; }

void CubeExplorer::OnR(vector<string>::iterator& iter) {
	RightTight();
	GetLeftReadyAndTight();
	macVec.push_back(Operation::R);
	handState.right.isReady = !handState.right.isReady;
}

void CubeExplorer::On_R(vector<string>::iterator& iter) {
	RightTight();
	GetLeftReadyAndTight();
	macVec.push_back(Operation::_R);
	handState.right.isReady = !handState.right.isReady;
}

void CubeExplorer::OnF(vector<string>::iterator& iter) {
	LeftTight();
	GetRightReadyAndTight();
	macVec.push_back(Operation::F);
	handState.left.isReady = !handState.left.isReady;
}

void CubeExplorer::On_F(vector<string>::iterator& iter) {
	LeftTight();
	GetRightReadyAndTight();
	macVec.push_back(Operation::_F);
	handState.left.isReady = !handState.left.isReady;
}

void CubeExplorer::OnRR(vector<string>::iterator& iter) {
	RightTight();
	LeftLoose();
	LeftReady();
	macVec.push_back(Operation::R);
	handState.right.isReady = !handState.right.isReady;
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "B";
		else if (*it == "B") *it = "D";
		else if (*it == "D") *it = "F";
		else if (*it == "F") *it = "U";
		else if (*it == "U'") *it = "B'";
		else if (*it == "B'") *it = "D'";
		else if (*it == "D'") *it = "F'";
		else if (*it == "F'") *it = "U'";
		else if (*it == "U2") *it = "B2";
		else if (*it == "B2") *it = "D2";
		else if (*it == "D2") *it = "F2";
		else if (*it == "F2") *it = "U2";
	}
}

void CubeExplorer::On_RR(vector<string>::iterator& iter) {
	RightTight();
	LeftLoose();
	LeftReady();
	macVec.push_back(Operation::_R);
	handState.right.isReady = !handState.right.isReady;
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "F";
		else if (*it == "B") *it = "U";
		else if (*it == "D") *it = "B";
		else if (*it == "F") *it = "D";
		else if (*it == "U'") *it = "F'";
		else if (*it == "B'") *it = "U'";
		else if (*it == "D'") *it = "B'";
		else if (*it == "F'") *it = "D'";
		else if (*it == "U2") *it = "F2";
		else if (*it == "B2") *it = "U2";
		else if (*it == "D2") *it = "B2";
		else if (*it == "F2") *it = "D2";
	}
}

void CubeExplorer::OnFF(vector<string>::iterator& iter) {
	LeftTight();
	RightLoose();
	RightReady();
	macVec.push_back(Operation::F);
	handState.left.isReady = !handState.left.isReady;
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "R";
		else if (*it == "R") *it = "D";
		else if (*it == "D") *it = "L";
		else if (*it == "L") *it = "U";
		else if (*it == "U'") *it = "R'";
		else if (*it == "R'") *it = "D'";
		else if (*it == "D'") *it = "L'";
		else if (*it == "L'") *it = "U'";
		else if (*it == "U2") *it = "R2";
		else if (*it == "R2") *it = "D2";
		else if (*it == "D2") *it = "L2";
		else if (*it == "L2") *it = "U2";
	}
}

void CubeExplorer::On_FF(vector<string>::iterator& iter) {
	LeftTight();
	RightLoose();
	RightReady();
	macVec.push_back(Operation::_F);
	handState.left.isReady = !handState.left.isReady;
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "L";
		else if (*it == "R") *it = "U";
		else if (*it == "D") *it = "R";
		else if (*it == "L") *it = "D";
		else if (*it == "U'") *it = "L'";
		else if (*it == "R'") *it = "U'";
		else if (*it == "D'") *it = "R'";
		else if (*it == "L'") *it = "D'";
		else if (*it == "U2") *it = "L2";
		else if (*it == "R2") *it = "U2";
		else if (*it == "D2") *it = "R2";
		else if (*it == "L2") *it = "D2";
	}
}

void CubeExplorer::OnRR2(vector<string>::iterator& iter) {
	RightTight();
	LeftLoose();
	LeftReady();
	macVec.push_back(Operation::R2);
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "D";
		else if (*it == "B") *it = "F";
		else if (*it == "D") *it = "U";
		else if (*it == "F") *it = "B";
		else if (*it == "U'") *it = "D'";
		else if (*it == "B'") *it = "F'";
		else if (*it == "D'") *it = "U'";
		else if (*it == "F'") *it = "B'";
		else if (*it == "U2") *it = "D2";
		else if (*it == "B2") *it = "F2";
		else if (*it == "D2") *it = "U2";
		else if (*it == "F2") *it = "B2";
	}

}

void CubeExplorer::OnFF2(vector<string>::iterator& iter) {
	LeftTight();
	RightLoose();
	RightReady();
	macVec.push_back(Operation::F2);
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "D";
		else if (*it == "R") *it = "L";
		else if (*it == "D") *it = "U";
		else if (*it == "L") *it = "R";
		else if (*it == "U'") *it = "D'";
		else if (*it == "R'") *it = "L'";
		else if (*it == "D'") *it = "U'";
		else if (*it == "L'") *it = "R'";
		else if (*it == "U2") *it = "D2";
		else if (*it == "R2") *it = "L2";
		else if (*it == "D2") *it = "U2";
		else if (*it == "L2") *it = "R2";
	}
}

void CubeExplorer::OnR2(vector<string>::iterator& iter) {
	RightTight();
	GetLeftReadyAndTight();
	macVec.push_back(Operation::R2);
}

void CubeExplorer::OnF2(vector<string>::iterator& iter) {
	LeftTight();
	GetRightReadyAndTight();
	macVec.push_back(Operation::F2);
}

void CubeExplorer::LeftLoose() {
	if (handState.left.isTight) {
		macVec.push_back(Operation::LeftLoose);
		handState.left.isTight = false;
	}
}

void CubeExplorer::LeftTight() {
	if (!handState.left.isTight) {
		if ((!handState.right.isReady) && (!handState.left.isReady)) {
			macVec.push_back(Operation::F);
		}
		macVec.push_back(Operation::LeftTight);
		handState.left.isTight = true;
	}
}

void CubeExplorer::LeftReady() {
	if (!handState.left.isReady) {
		macVec.push_back(Operation::F);
		handState.left.isReady = true;
	}
}

void CubeExplorer::RightLoose() {
	if (handState.right.isTight) {
		macVec.push_back(Operation::RightLoose);
		handState.right.isTight = false;
	}
}

void CubeExplorer::RightTight() {
	if (!handState.right.isTight) {
		if ((!handState.right.isReady) && (!handState.left.isReady)) {
			macVec.push_back(Operation::R);
		}
		macVec.push_back(Operation::RightTight);
		handState.right.isTight = true;
	}
}

void CubeExplorer::RightReady() {
	if (!handState.right.isReady) {
		macVec.push_back(Operation::R);
		handState.right.isReady = true;
	}
}

void CubeExplorer::GetLeftReadyAndTight() {
	if (handState.left.isReady) {
		if (!handState.left.isTight) {
			macVec.push_back(Operation::LeftTight);
			handState.left.isTight = true;
		}
	}
	else {
		if (handState.left.isTight) {
			macVec.push_back(Operation::LeftLoose);
			macVec.push_back(Operation::F);
			macVec.push_back(Operation::LeftTight);
		}
		else {
			macVec.push_back(Operation::F);
			macVec.push_back(Operation::LeftTight);
			handState.left.isTight = true;
		}
		handState.left.isReady = true;
	}
}

void CubeExplorer::GetRightReadyAndTight() {
	if (handState.right.isReady) {
		if (!handState.right.isTight) {
			macVec.push_back(Operation::RightTight);
			handState.right.isTight = true;
		}
	}
	else {
		if (handState.right.isTight) {
			macVec.push_back(Operation::RightLoose);
			macVec.push_back(Operation::R);
			macVec.push_back(Operation::RightTight);
		}
		else {
			macVec.push_back(Operation::R);
			macVec.push_back(Operation::RightTight);
			handState.right.isTight = true;
		}
		handState.right.isReady = true;
	}
}

void CubeExplorer::GetShortestWay() {
	string::size_type lastSpace = 0;	//记录上一次遇到空格的位置
	//将原始字符串分割为多个表示单个操作的字符串并存放到strNorVec容器中
	string::size_type i = 0;
	for (; i < target.length(); i++) {
		if (target[i] == ' ') {
			string strTemp;
			for (string::size_type index = lastSpace; index < i; index++) {
				strTemp.push_back(target[index]);
			}
			strNorVec.push_back(strTemp);
			lastSpace = i + 1;
		}
	}

	for (auto iter = strNorVec.begin(); iter != strNorVec.end(); iter++) {
		if (*iter == "R") OnR(iter);
		else if (*iter == "F") OnF(iter);
		else if (*iter == "R'") On_R(iter);
		else if (*iter == "F'") On_F(iter);
		else if (*iter == "R2") OnR2(iter);
		else if (*iter == "F2") OnF2(iter);
		else if (*iter == "B") {
			OnRR2(iter);
			OnF(iter);
		}
		else if (*iter == "L") {
			OnFF2(iter);
			OnR(iter);
		}
		else if (*iter == "U") {
			OnFF(iter);
			OnR(iter);
		}
		else if (*iter == "D") {
			OnRR(iter);
			OnF(iter);
		}
		else if (*iter == "B'") {
			OnRR2(iter);
			On_F(iter);
		}
		else if (*iter == "L'") {
			OnFF2(iter);
			On_R(iter);
		}
		else if (*iter == "U'") {
			OnFF(iter);
			On_R(iter);
		}
		else if (*iter == "D'") {
			OnRR(iter);
			On_F(iter);
		}
		else if (*iter == "B2") {
			OnRR2(iter);
			OnF2(iter);
		}
		else if (*iter == "L2") {
			OnFF2(iter);
			OnR2(iter);
		}
		else if (*iter == "U2") {
			OnFF(iter);
			OnR2(iter);
		}
		else if (*iter == "D2") {
			OnRR(iter);
			OnF2(iter);
		}
	}

	for (auto iter = macVec.begin(); iter != macVec.end(); iter++) {
		switch (*iter) {
		case Operation::F:
			vecStrSerial.push_back("#1P6T200\r\n");
			break;
		case Operation::_F:
			vecStrSerial.push_back("#1P7T200\r\n");
			break;
		case Operation::F2:
			vecStrSerial.push_back("#1P8T200\r\n");
			break;
		case Operation::LeftLoose:
			vecStrSerial.push_back("#2P0T200\r\n");
			break;
		case Operation::LeftTight:
			vecStrSerial.push_back("#2P1T200\r\n");
			break;
		case Operation::R:
			vecStrSerial.push_back("#3P6T200\r\n");
			break;
		case Operation::_R:
			vecStrSerial.push_back("#3P7T200\r\n");
			break;
		case Operation::R2:
			vecStrSerial.push_back("#3P8T200\r\n");
			break;
		case Operation::RightLoose:
			vecStrSerial.push_back("#4P0T200\r\n");
			break;
		case Operation::RightTight:
			vecStrSerial.push_back("#4P1T200\r\n");
			break;
		}
	}
}

void CubeExplorer::ShowOperations() {
	int cnt = 0;
	for (auto iter = macVec.cbegin(); iter != macVec.cend(); iter++) {
		if (*iter != Operation::LeftLoose&&*iter != Operation::LeftTight&&*iter != Operation::RightLoose&&*iter != Operation::RightTight) {
			cnt++;
		}
		cout << *iter <<"   ";
	}
	cout << endl;
	cout << "Final operations' count: " << cnt << endl;
	cout << "All operations' count: " << macVec.size() << endl;
	cout << endl;
}

void CubeExplorer::Reset() {
	handState = HandState(true, true, true, true);
	strNorVec.clear();
	macVec.clear();
	vecStrSerial.clear();
}

ostream& operator<<(ostream& os, const Operation& oper) {
	switch (oper) {
	case Operation::F:
		os << "F";
		break;
	case Operation::F2:
		os << "F2";
		break;
	case Operation::LeftLoose:
		os << "LeftLoose";
		break;
	case Operation::LeftTight:
		os << "LeftTight";
		break;
	case Operation::R:
		os << "R";
		break;
	case Operation::R2:
		os << "R2";
		break;
	case Operation::RightLoose:
		os << "RightLoose";
		break;
	case Operation::RightTight:
		os << "RightTight";
		break;
	case Operation::_F:
		os << "_F";
		break;
	case Operation::_R:
		os << "_R";
		break;
	}
	return os;
}
