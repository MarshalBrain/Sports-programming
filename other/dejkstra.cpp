const int INF = 1000000000;

int main() {
	int n;
	... ������ n ...
	vector < vector < pair<int,int> > > g (n);
	... ������ ����� ...
	int s = ...; // ��������� �������

	vector<int> d (n, INF),  p (n);
	d[s] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) { //���� �� ������ set
		int v = q.begin()->second; // ���������� �������
		q.erase (q.begin()); // �������� ������� ��������

		for (size_t j=0; j<g[v].size(); ++j) { //������ �� ������
			int to = g[v][j].first, //����� �������, � ������� ���������� �����
				len = g[v][j].second; // �� �����
			if (d[v] + len < d[to]) {
				q.erase (make_pair (d[to], to)); // �������� ������ ������ d[to]
				d[to] = d[v] + len; //
				p[to] = v; //����������
				q.insert (make_pair (d[to], to)); // ��������� ����������� ������ d[to]
			}
		}
	}
}
