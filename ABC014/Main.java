import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.NoSuchElementException;

class Main{
    int N, Q;
    ArrayList<Integer>[] graph;
    int root;//ルートの番号
	int[] parent;//親のノード番号
	int[] depth;//ルートからの深さ

    public void dfs (int v, int p, int d) {
        //ノードvの親 = p
		parent[v] = p;
		//ルートからノードvまでの深さ = d
		depth[v] = d;
        for(int i = 0; i<graph[v].size(); i++){
			if(graph[v].get(i) != p){
				dfs(graph[v].get(i),v,d + 1);
			}
		}
    }
    // rootの初期設定
    public void init(){
		dfs(root,-1,0);
	}
    //uとvのLCAを求める
	public int LCA(int u,int v){
		//uとvそれぞれのrootからの深さを揃える
		while(depth[u] > depth[v]) u = parent[u];
		while(depth[v] > depth[u]) v = parent[v];
		//最小祖先ノードで合流するまで１つ１つ向かっていく
		while(u != v){
			u = parent[u];
			v = parent[v];
		}
		return u;
	}
    // LCAを解く
    public void solve() {
		N = nextInt();
		graph = new ArrayList[N];
		root = 0;
		parent = new int[N];
		depth = new int[N];

		for(int i = 0;i < N;i++){
			graph[i] = new ArrayList<Integer>();
		}

		for(int i = 0;i < N - 1;i++){
			int x = nextInt() - 1;
			int y = nextInt() - 1;

			graph[x].add(y);
			graph[y].add(x);
		}

		init();

		Q = nextInt();
		for(int i = 0;i < Q;i++){
			int a = nextInt() - 1;
			int b = nextInt() - 1;

			int p = LCA(a,b);

			out.println(depth[a] - depth[p] + depth[b] - depth[p] + 1);
		}
	}
    /* Input */
	private static final InputStream in = System.in;
	private static final PrintWriter out = new PrintWriter(System.out);
	private final byte[] buffer = new byte[2048];
	private int p = 0;
	private int buflen = 0;

	private boolean hasNextByte() {
		if (p < buflen)
			return true;
		p = 0;
		try {
			buflen = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}
		if (buflen <= 0)
			return false;
		return true;
	}

	public boolean hasNext() {
		while (hasNextByte() && !isPrint(buffer[p])) {
			p++;
		}
		return hasNextByte();
	}
    private boolean isPrint(int ch) {
		if (ch >= '!' && ch <= '~')
			return true;
		return false;
	}

	private int nextByte() {
		if (!hasNextByte())
			return -1;
		return buffer[p++];
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = -1;
		while (isPrint((b = nextByte()))) {
			sb.appendCodePoint(b);
		}
		return sb.toString();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
    public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
