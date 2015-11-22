//x1y1为左下的坐标 x2y2为右上 的坐标 如果是顺序覆盖 0在最下面 数组尾在最上面
void dos(int x1,int y1,int x2,int y2,int y)
{
    if(x1>=x2||y1>=y2)return;
    if(y>n) //0~n-1
    {
        ans+=(x2-x1)*(y2-y1);
        return;
    }

    if(y1<p[y].y1)dos(max(p[y].x1,x1),y1,max(p[y].x1,x2),min(p[y].y1,y2),y+1);
    if(y2>p[y].y2)dos(min(x1,p[y].x2),max(y1,p[y].y2),min(p[y].x2,x2),y2,y+1);
    if(x1<p[y].x1)dos(x1,min(p[y].y2,y1),min(p[y].x1,x2),min(p[y].y2,y2),y+1);
    if(x2>p[y].x2)dos(max(p[y].x2,x1),max(p[y].y1,y1),x2,max(p[y].y1,y2),y+1);
}

