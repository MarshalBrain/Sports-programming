const int INF = 1000000000;

int main() {
	int n;
	... чтение n ...
	vector < vector < pair<int,int> > > g (n);
	... чтение графа ...
	int s = ...; // стартовая вершина

	vector<int> d (n, INF),  p (n);
	d[s] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) { //пока не пустой set
		int v = q.begin()->second; // извлечение вершины
		q.erase (q.begin()); // удаление первого элемента

		for (size_t j=0; j<g[v].size(); ++j) { //проход по списку
			int to = g[v][j].first, //номер вершины, в которую собирается пойти
				len = g[v][j].second; // ее длина
			if (d[v] + len < d[to]) {
				q.erase (make_pair (d[to], to)); // удаление старой версии d[to]
				d[to] = d[v] + len; //
				p[to] = v; //обновление
				q.insert (make_pair (d[to], to)); // добавляет обновленную версию d[to]
			}
		}
	}
}
