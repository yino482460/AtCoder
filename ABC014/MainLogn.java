import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class MainLogn {

	int N,Q;
	ArrayList<Integer>[] graph;


	int root;//ルートの番号
	int log;
	int[][] parent;//親のノード番号
	int[] depth;//ルートからの深さ

	public void dfs(int v,int p,int d){
		//ノードvの親 = p
		//parent[i][j] = ノードvから(2^i)回上った時の親ノード
		parent[0][v] = p;
		//ルートからノードvまでの深さ = d
		depth[v] = d;

		for(int i = 0;i < graph[v].size();i++){
			if(graph[v].get(i) != p){
				dfs(graph[v].get(i),v,d + 1);
			}
		}
	}

    public void init(){
    		dfs(root,-1,0);
    		for(int i = 0;i + 1 < log;i++){
    			for(int v = 0;v < N;v++){
    				if(parent[i][v] < 0){
    					//parent[i][v] = ノードvの親が存在しない場合いくら辿っても存在しない
    					parent[i + 1][v] = -1;
    				}else{

    					parent[i + 1][v] = parent[i][parent[i][v]];
    				}
    			}
    		}
    	}

        //uとvのLCAを求める
        	public int LCA(int u,int v){
        		if(depth[u] > depth[v]){
        			int tmp = u;
        			u = v;
        			v = tmp;
        		}

        		//この時点ではdepth[v] >= depth[u]が成り立つ

        		//uとvが同じ深さになるまで親ノードを上る
        		for(int i = 0;i < log;i++){
        			if(((depth[v] - depth[u]) >> i & 1) == 1){
        				v = parent[i][v];
        			}
        		}

        		//uが最小祖先の場合
        		if(u == v){
        			return u;
        		}

        		//uとvをそれぞれ親に上る
        		for(int i = log - 1;i >= 0;i--){
        			if(parent[i][u] != parent[i][v]){
        				u = parent[i][u];
        				v = parent[i][v];
        			}
        		}

        		return parent[0][u];
        	}

            public void solve() {
		N = nextInt();
		graph = new ArrayList[N];
		log = 0;
		while((1 << log) < N){
			log++;
		}

		root = 0;
		parent = new int[log][N];
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

    	public static void main(String[] args) {
    		out.flush();
    		new Main().solve();
    		out.close();
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
