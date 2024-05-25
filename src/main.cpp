#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stdbool.h>


struct FileData {
	int lineK;
	std::string lineV;
};

bool is_digits(const std::string &rawLine) {
	return rawLine.find_first_not_of("0123456789") == std::string::npos;
}

FileData* merge_sort(FileData *inpt, FileData *tmpp, const int left, const int right) {
	if (left == right) {
		tmpp[left] = inpt[left];
		return tmpp;
	}

	int mid = (left+right)/2;
	FileData *rb = merge_sort(inpt, tmpp, mid+1, right);
	FileData *lb = merge_sort(inpt, tmpp, left, mid);
	FileData *res = lb == inpt ? tmpp : inpt;

	int lc = left;
    int rc = mid + 1;
 	for (int i = left; i <= right; i++) {
  		if (lc <= mid && rc <= right) {
   			if (lb[lc].lineK < rb[rc].lineK) {
				res[i] = lb[lc];
				lc++;
			} else {
    			res[i] = rb[rc];
    			rc++;
   			}
		} else if (lc <= mid) {
			res[i] = lb[lc];
			lc++;
		} else {
			res[i] = rb[rc];
			rc++;
		}
	}
	return res;
}

int main(int argc, char* argv[]) {
	int t = clock();

	if (argc!=3) {
        return 1;
    }

    std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);
	std::string rawLine;

	if (!inputFile.is_open() || !outputFile.is_open()) {
        return 2;
    }

	getline(inputFile, rawLine);
	int N = stoi(rawLine);
	FileData *newData, *anotherData;
	newData = new FileData[N];
	anotherData = new FileData[N];
	int i;

    if (N < 0) {
        return 3;
    }

	try {
		for (i=0; getline(inputFile, rawLine); i++) {
			newData[i].lineK = stoi(rawLine.substr(0, rawLine.find(' ')));
			newData[i].lineV = (' ' + rawLine.substr(rawLine.find(' ') + 1));
		}
	} catch (...) {
		return 3;
	};


	for (i=0; getline(inputFile, rawLine); i++) {
		if (rawLine.substr(0, rawLine.find(' ')) == std::to_string(stoi(rawLine.substr(0, rawLine.find(' '))))) {
			newData[i].lineK = stoi(rawLine.substr(0, rawLine.find(' ')));
			newData[i].lineV = (' ' + rawLine.substr(rawLine.find(' ') + 1));
		}
	}

	inputFile.close();
	std::cout << "FileReadTime: " << clock()-t;

 	newData = merge_sort(newData, anotherData, 0, N-1);
 	std::cout << "\nFileSortTime: " << clock() - t;

 	outputFile << N;
 	outputFile << "\n" << newData[i].lineK << newData[i].lineV;
 	std::cout << "\nFileWriteTime: " << clock() - t;

 	outputFile.close();
 	return 0;
}
