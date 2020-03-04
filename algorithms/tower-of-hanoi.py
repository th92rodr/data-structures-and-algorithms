
def tower(disk_number, source, intermediate, destination):
    if disk_number == 1:
        print('{}->{}'.format(source, destination))
    else:
        tower(disk_number - 1, source, destination, intermediate)
        print('{}->{}'.format(source, destination))
        tower(disk_number - 1, intermediate, source, destination)


if __name__ == '__main__':
    tower(3, 'source', 'intermediate', 'destination')
