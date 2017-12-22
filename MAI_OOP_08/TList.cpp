#include "TList.h"
#include "TIterator.h"

template <class T>
TList<T>::TList() {
	first = nullptr;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TList<T>& list) {

	std::shared_ptr<TListItem<T>> item = list.first;
	int i = 1;
	while (item != nullptr)
	{
		std::cout << "[" << i << "]";
		item->GetFigure()->Print();
		item = item->GetNext();
		i++;
	}

	return os;
}

template <class T>
int TList<T>::length() {
	int i = 0;
	std::shared_ptr<TListItem<T>> item = this->first;
	while (item != nullptr)
	{
		item = item->GetNext();
		i++;
	}
	return i;
}

template <class T>
void TList<T>::addFirst(std::shared_ptr<T> &figure) {
	std::shared_ptr<TListItem<T>> other = std::make_shared<TListItem<T>>(figure);

	other->SetNext(first);
	first = other;
}

template <class T>
void TList<T>::insert(int index, std::shared_ptr<T> &figure) {
	std::shared_ptr<TListItem<T>>iter = this->first;
	std::shared_ptr<TListItem<T>> other = std::make_shared<TListItem<T>>(figure);
	//int i = 0;
	if (index == 1) {
		other->SetNext(iter);
		this->first = other;
	}
	else {
		if (index <= this->length()) {
			int i = 1;
			for (i = 1; i < index - 1; ++i) {
				iter = iter->GetNext();
			}
			other->SetNext(iter->GetNext());
			iter->SetNext(other);
		}
		else {
			std::cout << "error" << std::endl;
		}
	}
}

template <class T>
void TList<T>::addLast(std::shared_ptr<T> &figure) {
	std::shared_ptr<TListItem<T>> other = std::make_shared<TListItem<T>>(figure);
	std::shared_ptr<TListItem<T>> iter = this->first;
	if (first != nullptr) {
		while (iter->GetNext() != nullptr) {
			iter = iter->SetNext(iter->GetNext());
		}
		iter->SetNext(other);// little bit strange
		other->SetNext(nullptr);
	}
	else {
		first = other;
	}
}

template <class T>
bool TList<T>::empty() {
	return first == nullptr;
}

template <class T>
void TList<T>::delElement(int &index)
{
	std::shared_ptr<TListItem<T>>iter = this->first;
	//std::shared_ptr<TListItem> other = std::make_shared<TListItem>(figure);
	//int i = 0;
	if (index <= this->length()) {
	if (index == 1) {
		this->first = iter->GetNext();
	}
	else {
		int i = 1;
		for (i = 1; i < index - 1; ++i) {
			iter = iter->GetNext();
		}
		iter->SetNext(iter->GetNext()->GetNext());
	}

	}
	else {
		std::cout << "error" << std::endl;
	}
}

template <class T>
void TList<T>::eraseList() {
	first = nullptr;
}

template <class T>
TList<T>::~TList() {
	std::cout << "List deleted!" << std::endl;
	//delete first;
}
template <class T>
TIterator<TListItem<T>, T> TList<T>::begin()
{
	return TIterator<TListItem<T>, T>(first);
}

template <class T>
TIterator<TListItem<T>, T> TList<T>::end()
{
	return TIterator<TListItem<T>, T>(nullptr);
}

template <class T>
std::shared_ptr<TListItem<T>> TList<T>::PSort(std::shared_ptr<TListItem<T>> &first)
{
	if (first == nullptr || first->GetNext() == nullptr) {
		return first;
	}

	std::shared_ptr<TListItem<T>> partitionedEl = Partition(first);
	std::shared_ptr<TListItem<T>> leftPartition = partitionedEl->GetNext();
	std::shared_ptr<TListItem<T>> rightPartition = first;

	partitionedEl->SetNext(nullptr);

	if (leftPartition == nullptr) {
		leftPartition = first;
		rightPartition = first->GetNext();
		first->SetNext(nullptr);
	}

	rightPartition = PSort(rightPartition);
	leftPartition = PSort(leftPartition);
	std::shared_ptr<TListItem<T>> iter = leftPartition;
	while (iter->GetNext() != nullptr) {
		iter = iter->GetNext();
	}

	iter->SetNext(rightPartition);

	return leftPartition;
}

template <class T>
std::shared_ptr<TListItem<T>> TList<T>::Partition(std::shared_ptr<TListItem<T>> &first)
{
	std::lock_guard<std::mutex> lock(mutex);
	if (first->GetNext()->GetNext() == nullptr) {
		if (first->GetNext()->GetFigure()->SquareF() > first->GetFigure()->SquareF()) {
			return first->GetNext();
		}
		else {
			return first;
		}
	}
	else {
		std::shared_ptr<TListItem<T>> i = first->GetNext();
		std::shared_ptr<TListItem<T>> pivot = first;
		std::shared_ptr<TListItem<T>> lastElSwapped = (pivot->GetNext()->GetFigure()->SquareF() >= pivot->GetFigure()->SquareF()) ? pivot->GetNext() : pivot;

		while ((i != nullptr) && (i->GetNext() != nullptr)) {
			if (i->GetNext()->GetFigure()->SquareF() >= pivot->GetFigure()->SquareF()) {
				if (i->GetNext() == lastElSwapped->GetNext()) {
					lastElSwapped = lastElSwapped->GetNext();
				}
				else {
					std::shared_ptr<TListItem<T>> tmp = lastElSwapped->GetNext();
					lastElSwapped->SetNext(i->GetNext());
					i->SetNext(i->GetNext()->GetNext());
					lastElSwapped = lastElSwapped->GetNext();
					lastElSwapped->SetNext(tmp);
				}
			}
			i = i->GetNext();
		}
		return lastElSwapped;
	}
}

template <class T>
void TList<T>::Sort()
{
	if (first == nullptr)
		return;
	std::shared_ptr<TListItem<T>> tmp = first->GetNext();
	first->SetNext(PSort(tmp));
}

template <class T>
void TList<T>::ParSort()
{
	if (first == nullptr)
		return;
	std::shared_ptr<TListItem<T>> tmp = first->GetNext();
	first->SetNext(PParSort(tmp));
}

template <class T>
std::shared_ptr<TListItem<T>> TList<T>::PParSort(std::shared_ptr<TListItem<T>> &first)
{
	if (first == nullptr || first->GetNext() == nullptr) {
		return first;
	}

	std::shared_ptr<TListItem<T>> partitionedEl = Partition(first);
	std::shared_ptr<TListItem<T>> leftPartition = partitionedEl->GetNext();
	std::shared_ptr<TListItem<T>> rightPartition = first;

	partitionedEl->SetNext(nullptr);

	if (leftPartition == nullptr) {
		leftPartition = first;
		rightPartition = first->GetNext();
		first->SetNext(nullptr);
	}

	std::packaged_task<std::shared_ptr<TListItem<T>>(std::shared_ptr<TListItem<T>>&)>
		task1(std::bind(&TList<T>::PParSort, this, std::placeholders::_1));
	std::packaged_task<std::shared_ptr<TListItem<T>>(std::shared_ptr<TListItem<T>>&)>
		task2(std::bind(&TList<T>::PParSort, this, std::placeholders::_1));
	auto rightPartitionHandle = task1.get_future();
	auto leftPartitionHandle = task2.get_future();

	std::thread(std::move(task1), std::ref(rightPartition)).join();
	rightPartition = rightPartitionHandle.get();
	std::thread(std::move(task2), std::ref(leftPartition)).join();
	leftPartition = leftPartitionHandle.get();
	std::shared_ptr<TListItem<T>> iter = leftPartition;
	while (iter->GetNext() != nullptr) {
 		iter = iter->GetNext();
	}

	iter->SetNext(rightPartition);
	return leftPartition;
}
#include "Figure.h"
template class TList<Figure>;
template std::ostream& operator<<(std::ostream &out, const TList<Figure> &figure);