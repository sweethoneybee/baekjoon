const challenge = {
    /*
     * addData �Լ��� �ϼ������ּ���.
     */
    addData: async function(name, description) {
      // ���� ���� �ʿ� �����͸� ����մϴ�.
      //
      fetch('', {
        method: '',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({
          
        })
      }).then(function(response) {
        return response.json();
      }).then(function(data) {
        // Table�� �� �����͸� �־� �����ݴϴ�.
        //
      });
    },
  
    /*
     * removeData �Լ��� �ϼ������ּ���.
     */
    removeData: function(index) {
      // ���� ���� �ʿ� ������ ���� ��û�� �մϴ�.
      //
      fetch('', {
        method: '',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({
          
        })
      }).then(function(response) {
        return response.json();
      }).then(function(data) {
        // Table���� index ������ ã�� �����͸� �������ݴϴ�.
        //
      });
    }
  }