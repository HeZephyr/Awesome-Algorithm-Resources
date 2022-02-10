int pnpoly(int n, double pos_x, double pos_y, double vert[][2])
{
    int i, j, c = 0;
	
	for (i = 0, j = n - 1; i < n; j = i++)
	{
		if (((vert[i][1] > pos_y) != (vert[j][1] > pos_y)) &&
			(pos_x < (vert[j][0] - vert[i][0]) * (pos_y - vert[i][1]) / (vert[j][1] - vert[i][1]) + vert[i][0]))
		{
			c = !c;
		}
	}
	
	return c;

}
