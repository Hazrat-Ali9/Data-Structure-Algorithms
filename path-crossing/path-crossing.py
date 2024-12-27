class Solution:
    def isPathCrossing(self, path: str) -> bool:
        moves = {
            "N" : (0, 1),
            "S" : (0, -1),
            "W" : (-1, 0),
            "E" : (1, 0)
        }
        vis = {(0, 0)}
        x, y = 0, 0
        for c in path:
            dx, dy = moves[c]
            x += dx
            y += dy
            if (x, y) in vis:
                return True
            vis.add((x, y))
        return False